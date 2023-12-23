#include<iostream>
using namespace std;
int map[1001][1001], dp[1001][100], l[1001], r[1001];

int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    dp[0][0] = map[0][0];

    for(int i = 1; i < M; i++) {
        dp[0][i] = dp[0][i-1] + map[0][i];
    }

    for(int i = 1; i < N; i++) {
        r[0] = dp[i-1][0] + map[i][0];
        for(int j = 0; j < M-1; j++) {
            r[j+1] = max(r[j], dp[i-1][j+1]) + map[i][j+1];            
        }

        l[M-1] = dp[i-1][M-1] + map[i][M-1];
        for(int j = M-2; j >= 0; j--) {
            l[j] = max(l[j+1], dp[i-1][j]) + map[i][j];
        }

        for(int j = 0; j < M; j++) {
            dp[i][j] = max(r[j], l[j]);
        }
    }

    cout << dp[N-1][M-1];

    return 0;
}