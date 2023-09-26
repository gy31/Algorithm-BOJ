#include<stdio.h>
int main()
{
    int n, cnt = 0, tmp, a;
    int i;
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        tmp = i;
        a = 0;
        while(tmp > 0) {
            a += tmp % 10;
            tmp /= 10;
        }
        if(i % a == 0) cnt++;
    }

    printf("%d", cnt);

    return 0;
}