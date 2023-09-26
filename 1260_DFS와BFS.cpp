#define M 1010
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
queue <int> q;
int map[M][M], chk[M], n, m, v;
void dfs(int k) {
    int i;
    chk[k] = 1;
    printf("%d ", k);
    for(i = 1; i <= n; i++) {
        if(map[k][i] && !chk[i]) {
            dfs(i);
        }
    }
}
void bfs(int k) {
    int i, x;
    q.push(k);
    chk[k] = 1;
    while(!q.empty()) {
        x = q.front();
        q.pop();
        printf("%d ", x);
        for(i = 1; i <= n; i++) {
            if(map[x][i] && !chk[i]) {
                q.push(i);
                chk[i] = 1;
            }
        }
    }
}
int main()
{
    int a, b, i;
    scanf("%d%d%d", &n, &m, &v);
    for(i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        map[a][b] = map[b][a] = 1;
    }

    dfs(v);
    printf("\n");
    fill(chk, chk+M, 0);
    bfs(v);

    return 0;
}