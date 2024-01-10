#include<iostream>
using namespace std;
int M, N;
int map[501][501], dp[501][501], dx[4] = {0,0,-1,1}, dy[4] = {1, -1, 0, 0};
int dfs(int x, int y) {
    if(x == M-1 && y == N-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;

    for(int i = 0; i < 4; i++) {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx < 0 || nx >= M || ny < 0 || ny >= N || map[x][y] <= map[nx][ny]) continue;

        dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}
int main() {
    cin >> M >> N;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0,0);


    return 0;
}