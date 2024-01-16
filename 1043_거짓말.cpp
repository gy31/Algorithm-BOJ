#define MA 51
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> party[MA];
int N, M, k, v[MA], know[MA];
int dfs(int a) {
	if(v[a] == a) return v[a];
	v[a] = dfs(v[a]);
	return v[a];
}
int main() {
    int ans = 0;
	scanf("%d%d%d", &N, &M, &k);
	
	if(k == 0) {
		printf("%d", M);
		return 0;
	}
	
	for(int i = 1; i <= N; i++) v[i] = i;

	for(int i = 1; i <= k; i++) {
		scanf("%d", &know[i]);

		if(i >= 2) {
			int a, b;
			a = dfs(know[i-1]);
			b = dfs(know[i]);
			if(a != b) v[b] = a;
		}
	}

	for(int i = 1; i <= M; i++) {
		int t;
		scanf("%d", &t);
		for(int j = 0; j < t; j++) {
			int x;
			scanf("%d", &x);
			party[i].push_back(x);
            if(j >= 1) {
                int a, b;
                a = dfs(party[i][j-1]);
                b = dfs(party[i][j]);
                if(a != b) v[b] = a;
		    }
		}
	}

    for(int i = 1; i <= M; i++) {
        if(dfs(know[1]) != dfs(party[i][0])) ans++;
    }

    printf("%d", ans);

	return 0;
}