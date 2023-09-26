#include<stdio.h>
int arr[15][15];
int main()
{
    int i, j, t, k, n;
    scanf("%d", &t);

    for(i = 1; i <= 14; i++) arr[0][i] = i;

    for(i = 1; i <= 14; i++) {
        for(j = 1; j <= 14; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    for(i = 0; i < t; i++) {
        scanf("%d%d", &k, &n);
        
        printf("%d\n", arr[k][n]);
    }
    

    return 0;
}