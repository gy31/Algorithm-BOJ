#include<stdio.h>
#define max(x,y) (((x)>(y)) ? (x):(y))
int arr[501][501];
int main(){
    int i, j, n;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(i = n-2; i >= 0; i--) {
        for(j = 0; j <= i; j++) {
            arr[i][j] = max(arr[i][j] + arr[i+1][j], arr[i][j] + arr[i+1][j+1]);
        }
    }

    printf("%d", arr[0][0]);

    return 0;
}