#define MA 3001
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, cnt[MA];
struct line {
	int x1, y1, x2, y2;
};
vector<line> v;
vector<int> group;
long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long a = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if(a > 0) return 1;
	else if(a == 0) return 0;
	else return -1;
}
int find(int a) {
	if(a == group[a]) return a;
	group[a] = find(group[a]);
	return group[a];
}
int main() {
	int maxCnt = 0, groupCnt = 0;
    bool sw;
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		v.push_back({a, b, c, d});
		group.push_back(i);
	}

	for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            long long x1, x2, x3, x4, y1, y2, y3, y4, a, b, c, d;
            x1 = v[i].x1; y1 = v[i].y1; x2 = v[i].x2; y2 = v[i].y2;
            x3 = v[j].x1; y3 = v[j].y1; x4 = v[j].x2; y4 = v[j].y2;

            a = ccw(x1, y1, x2, y2, x3, y3);
            b = ccw(x1, y1, x2, y2, x4, y4);
            c = ccw(x3, y3, x4, y4, x1, y1);
            d = ccw(x3, y3, x4, y4, x2, y2);

            if(a*b == 0 && c*d == 0) {
                sw = min(x1, x2) <= max(x3, x4) && max(x1, x2) >= min(x3, x4) && min(y1, y2) <= max(y3, y4) && max(y1, y2) >= min(y3, y4);
            }
            else if(a*b <= 0 && c*d <= 0) sw = 1;
            else sw = 0;

            if(sw == 1) {
                int first = find(i);
                int second = find(j);
                if(first != second) group[second] = first;
            }
        }
	}

	for(int i = 0; i < N; i++) {
		int a = find(i);
		cnt[a]++;
		if(cnt[a] > maxCnt) maxCnt = cnt[a];
	}

	for(int i = 0; i < N; i++) {
		if(cnt[i] != 0) groupCnt++;
	}

	printf("%d\n%d", groupCnt, maxCnt);

	return 0;
}