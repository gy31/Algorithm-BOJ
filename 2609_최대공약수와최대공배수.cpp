#include<stdio.h>
int main()
{
    int a, b, x, y, tmp;
    scanf("%d%d", &a, &b);
    x = a; y =b;

    while(b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    printf("%d\n%d", a, (x*y)/a);
    

    return 0;
}