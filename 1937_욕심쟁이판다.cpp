#include<stdio.h>
#include<algorithm>
using namespace std;
int n, map[501][501], dp[501][501], dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
int dfs(int x, int y) {
    if(dp[x][y]) return dp[x][y];

    for(int i = 0; i < 4; i++) {
        int nx, ny;
        nx = dx[i] + x;
        ny = dy[i] + y;
        if(nx < 1 || nx > n || ny < 1 || ny > n || map[x][y] >= map[nx][ny]) continue;
        dp[x][y] = max(dfs(nx, ny), dp[x][y]);
    }
    return ++dp[x][y];
}
int main() {
    int ans = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!dp[i][j]) {
                int x = dfs(i, j);
                if(ans < x) ans = x;
            }
        }
    }

    printf("%d", ans);

    return 0;
}