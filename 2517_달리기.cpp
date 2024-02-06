#define MA 1 << 20
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, tree[MA], arr[MA], ans, p;
vector<pair<int, int>> num;
int update(int x, int y, int s, int idx) {
    if(s < x || y < s) return tree[idx];
    if(x == s && y == s) return tree[idx]=1;

    int mid = (x+y) / 2;
    tree[idx] = update(x, mid, s, idx*2) + update(mid+1, y, s, idx*2+1);
    return tree[idx];
}
int query(int x, int y, int s, int e, int idx) {
    if(s <= x && y <= e) return tree[idx];
    if(s > y || e < x) return 0;

    int mid = (x+y) / 2;
    return query(x, mid, s, e, idx*2) + query(mid+1, y, s, e, idx*2+1);
}
int main() {
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		num.push_back({a, i});
	}

	sort(num.begin(), num.end());

	for(int i = 0; i < N; i++) {
		num[num[i].second].first = i+1;
	}

	for(int i = 0; i < N; i++) {
        printf("%d\n", query(1, N, num[i].first+1, N, 1)+1);
        update(1, N, num[i].first, 1);
    }

	return 0;
}