#include<stdio.h>
int arr[5001];
int main()
{
    int i, n;
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        arr[i] = -1;
    }

    for(i = 3; i <= n; i++) {
        if(arr[i-3] != -1) arr[i] = arr[i-3] + 1;
    }

    for(i = 5; i <= n; i++) {
        if(arr[i-5] != -1) arr[i] = arr[i-5] + 1;
    }
    
    printf("%d", arr[n]);

    return 0;
}