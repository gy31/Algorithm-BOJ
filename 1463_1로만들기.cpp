#include<stdio.h>
int arr[1000001] = {0,0,1,1,};
int main()
{
    int i, n;
    scanf("%d", &n);

    for(i = 4; i <= n; i++) {
        arr[i] = arr[i-1] + 1;
        if(i % 2 == 0 && arr[i/2] + 1 < arr[i]) {
            arr[i] = arr[i/2] + 1;
        }
        if(i % 3 == 0 && arr[i/3] + 1 < arr[i]) {
            arr[i] = arr[i/3] + 1;
        }
    }

    printf("%d", arr[n]);

    return 0;
}