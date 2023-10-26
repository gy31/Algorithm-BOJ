#include<stdio.h>
long long int arr[101][21];
int main() {
    int i, j, n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    arr[0][x] = 1;
    for(i = 1; i < n; i++) {
        scanf("%d", &x);
        for(j = 0; j < 21; j++) {
            if(arr[i-1][j] != 0) {
                if(j-x >= 0) arr[i][j-x] += arr[i-1][j];
                if(j+x <= 20) arr[i][j+x] += arr[i-1][j];
            }
        }
    }

    printf("%lld", arr[n-2][x]);

    return 0;
}