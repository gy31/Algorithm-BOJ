#define MA 100001
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int V, chk[MA], maxLen, maxV;
vector<pair<int,int>> map[MA];
void dfs(int k, int length) {
	chk[k] = 1;
	if(length > maxLen) {
		maxLen = length;
		maxV = k;
	}
	for(int i = 0; i < map[k].size(); i++) {
		if(!chk[map[k][i].first]) {
			dfs(map[k][i].first, length + map[k][i].second);
		}
	}
}
int main() {
	scanf("%d", &V);

	for(int i = 1; i <= V; i++) {
        int a, b, c;
        scanf("%d", &a);
		while(1) {
			scanf("%d", &b);
			if(b == -1) break;
			scanf("%d", &c);
			map[a].push_back({b, c});
            map[b].push_back({a, c});
		}
	}
	maxLen = -1;
	dfs(1, 0);
	fill(chk, chk+MA, 0);
	maxLen = -1;
	dfs(maxV, 0);

	printf("%d", maxLen);

	return 0;
}