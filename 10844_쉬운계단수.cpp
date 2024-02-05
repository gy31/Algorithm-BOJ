#include<iostream>
using namespace std;
int N;
long long dp[101][10], ans;
int main() {
    cin >> N;

    for(int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j != 0) dp[i][j] += dp[i-1][j-1];
            if(j != 9) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= 1000000000;
        }
    }

    for(int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % 1000000000;
    }

    cout << ans;

    return 0;
}