#define MA 401
#include<stdio.h>
int N, map[MA][MA];
long long int dp[MA][MA];
long long int dfs(int x, int y) {
    int n = map[x][y];
    if(x == N && y == N) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    if(x+n <= N) dp[x][y] += dfs(x+n, y);
    if(y+n <= N) dp[x][y] += dfs(x, y+n);
    
    return dp[x][y];
}
int main() {
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }

    printf("%lld", dfs(1,1));

    return 0;
}