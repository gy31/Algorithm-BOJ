#include<stdio.h>
int arr[501][501];
int main()
{
    int i, j, n;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    return 0;
}