#include<stdio.h>
int num[100001], dp[100001];
int main()
{
    int i, n, max;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    max = dp[0] = num[0];

    for(i = 1; i < n; i++) {
        if(dp[i-1] + num[i] > num[i]) dp[i] = dp[i-1] + num[i];
        else dp[i] = num[i];

        if(dp[i] > max) max = dp[i];
    }

    printf("%d", max);

    return 0;
}