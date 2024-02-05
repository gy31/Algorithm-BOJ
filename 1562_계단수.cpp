#include<iostream>
using namespace std;
int N;
long long dp[101][10][1 << 10], ans;
int main() {
    cin >> N;

    for(int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 1; k < (1<<10); k++) {
                if(j != 0) dp[i][j][k | (1<<j)] += dp[i-1][j-1][k];
                if(j != 9) dp[i][j][k | (1<<j)] += dp[i-1][j+1][k];
                dp[i][j][k | 1<<j] %= 1000000000;
            }
        }
    }

    for(int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i][(1<<10)-1]) % 1000000000;
    }

    cout << ans;

    return 0;
}