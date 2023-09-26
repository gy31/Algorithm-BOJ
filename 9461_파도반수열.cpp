#include<stdio.h>
long long int dp[101] = {0,1,1,1,2,2};
int main()
{
    int i, t, n;
    scanf("%d", &t);

    for(i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    for(i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}