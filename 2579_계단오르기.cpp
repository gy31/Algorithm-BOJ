#include<stdio.h>
int dp1[301], dp2[301]; // 연속, 건너
int main()
{
    int i, n, tmp, answer;
    scanf("%d", &n);
    scanf("%d", &dp1[1]); dp2[1] = dp1[1];
    scanf("%d", &dp2[2]); dp1[2] = dp2[2] + dp1[1];

    for(i = 3; i <= n; i++) {
        scanf("%d", &tmp);
        dp1[i] = dp2[i-1] + tmp;
        if(dp1[i-2] < dp2[i-2]) dp2[i] = dp2[i-2] + tmp;
        else dp2[i] = dp1[i-2] + tmp;
    }

    if(dp1[n] > dp2[n]) answer = dp1[n];
    else answer = dp2[n];
    printf("%d", answer);

    return 0;
}