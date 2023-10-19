#include<stdio.h>
int map[1001][1001], chk[1001];
int n, cnt = 0;
void dfs(int a, int b) {
    map[a][b] = map[b][a] = 0;
    chk[a] = chk[b] = 1;

    for(int i = 1; i <= n; i++) {
        if(map[b][i] == 1 && chk[i] == 0) {
            dfs(b, i);
        }
    }
}
int main() {
    int i, j, m, u, v;

    scanf("%d%d", &n, &m);

    for(i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        map[u][v] = map[v][u] = 1;
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(map[i][j] == 1 && chk[i] == 0 && chk[j] == 0) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    printf("%d", cnt);

    return 0;
}