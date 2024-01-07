#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 100000001
vector<int> ans;
int map[1010][1010], dis[1010], via[1010], chk[1010];
int n, m, st, ed;
void find(int x) {
	if(x == 0) return;
	find(via[x]);
	ans.push_back(x);
}
void func(int x) {
	int min, mink;
    fill(dis, dis+1010, INF);
    dis[x] = 0;

    for(int i = 1; i < n; i++) {
        if(x == -1) return;
        chk[x] = 1; min = INF; mink = -1;

        for(int j = 1; j <= n; j++) {
            int t = dis[x] + map[x][j];
            if(!chk[j] && dis[j] > t) {
                dis[j] = t;
                via[j] = x;
            }
            if(!chk[j] && min > dis[j]) {
                min = dis[j];
                mink = j;
            }
        }
        x = mink;
    }
}
int main() {
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {
		dis[i] = INF;
		for(int j = 1; j <= n; j++) {
			if(i != j) map[i][j] = INF;
		}
	}

	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(map[a][b] > c) map[a][b] = c;
	}

	scanf("%d%d", &st, &ed);

	dis[st] = 0;
	func(st);

	printf("%d\n", dis[ed]);
	find(ed);

	printf("%d\n", ans.size());

	for(int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}