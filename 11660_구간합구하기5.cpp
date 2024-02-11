#include<stdio.h>
int arr[1025][1025], dp[1025][1025];
int main()
{
    int i, j, n, m, w, x, y, z, tmp = 0, answer;
    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }

    for(i = 0; i < m; i++) {
        scanf("%d%d%d%d", &w, &x, &y, &z);
        answer = dp[y][z] - dp[w-1][z] - dp[y][x-1] + dp[w-1][x-1];
        printf("%d\n", answer);
    }

    return 0;
}