#define MA 100001
#include<stdio.h>
#include<vector>
using namespace std;
int N, M, cnt, chk[MA], parent[50][MA], depth[MA];
vector<int> map[MA];
void find(int a, int b) {
	if(depth[a] != depth[b]) {
		if(depth[a] < depth[b]) {
			int t = a;
			a = b;
			b = t;
		}
		int t = depth[a] - depth[b];

		for(int i = 0; i <= cnt; i++) {
			if(t & (1 << i)) {
				a = parent[i][a];
			}
		}
	}
	if(a == b) {
		printf("%d\n", a);
		return;
	}
	if(depth[a] == depth[b]) {
		for(int i = cnt; i >= 0; i--) {
			if(parent[i][a] != parent[i][b]) {
				a = parent[i][a];
				b = parent[i][b];
			}
		}
		printf("%d\n", parent[0][a]);
		return;
	}

}
void dfs(int k, int y, int d) {
	chk[k] = 1;
	parent[0][k] = y;
	depth[k] = d;
	for(int i = 0; i < map[k].size(); i++) {
		if(!chk[map[k][i]]) {
			dfs(map[k][i], k, d+1);
		}
	}
}
int main() {
	scanf("%d", &N);

	for(int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}

	dfs(1, 0, 0);

	for(int i = 1; i <= N; i*=2) cnt++;

	for(int i = 1; i <= cnt; i++) {
		for(int j = 1; j <= N; j++) {
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}

	scanf("%d", &M);

	for(int i = 1; i<= M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		find(a, b);
	}

	return 0;
}