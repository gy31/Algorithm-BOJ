#define MAX(x,y) ((x) > (y))?(x):(y)
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1001], dp[1001];
int main()
{
    int i, j, n, answer=1;
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }

    for(i = 2; i <= n; i++) {
        for(j = 1; j < i; j++) {
            if(a[i] > a[j]) {
                dp[i] = MAX(dp[i], dp[j]+1);
            }
            answer = MAX(answer, dp[i]);
        }
    }

    printf("%d", answer);
    

    return 0;
}