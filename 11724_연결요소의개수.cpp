#include<stdio.h>
int map[1001][1001], chk[1001];
int n, cnt = 0;
void dfs(int a) {
    chk[a] = 1;

    for(int i = 1; i <= n; i++) {
        if(map[a][i] && !chk[i]) dfs(i);
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
        if(!chk[i]) {
            cnt++;
            dfs(i);
        }
    }

    printf("%d", cnt);

    return 0;
}