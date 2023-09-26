#include<stdio.h>
int main()
{
    int i, n, k, sum = 0;
    scanf("%d%d", &n, &k);

    for(i = 1; i <= k; i++) {
        sum += i;
    }
    
    if(n >= sum) {
        
    }
    else printf("-1");

    return 0;
}