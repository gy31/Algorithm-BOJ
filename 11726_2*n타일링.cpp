#include<stdio.h>
int arr[1001] = {0, 1, 2,};
int main()
{
    int i, n;
    scanf("%d", &n);

    for(i = 3; i <= n; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }

    printf("%d", arr[n]);

    return 0;
}