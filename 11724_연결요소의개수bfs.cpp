#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
queue <int> q;
int n;
int map[1001][1001], chk[1001];
void bfs(int a) {
    int x;
    chk[a] = 1;
    q.push(a);

    while(!q.empty()) {
        x = q.front();
        q.pop();

        for(int i = 1; i <= n; i++) {
            if(map[x][i] && !chk[i]) {
                q.push(i);
                chk[i] = 1;
            }
        }
    }
}
int main() {
    int m, u, v, cnt = 0;

    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        map[u][v] = map[v][u] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(!chk[i]) {
            cnt++;
            bfs(i);
        }
    }

    printf("%d", cnt);

    return 0;
}