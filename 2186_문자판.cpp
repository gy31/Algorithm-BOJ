#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int N, M, K, dp[101][101][81], dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0}, ans;
char map[101][101];
string word;
int dfs(int x, int y, int n) {
    if(dp[x][y][n] != -1) return dp[x][y][n];
    if(n == word.length()) return 1;
    dp[x][y][n] = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= K; j++) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if(word[n] != map[nx][ny]) continue;
            dp[x][y][n] += dfs(nx, ny, n+1);
        }
    }
    return dp[x][y][n];
}
int main() {
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cin >> word;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] == word[0]) {
                ans += dfs(i, j, 1);
            }
        }
    }

    cout << ans;

    return 0;
}