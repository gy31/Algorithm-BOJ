#include <stdio.h>
int arr[1001][10];

int main() {
    int i, j, n;
    scanf("%d", &n);

    for(i = 0; i < 1001; i++) {
        for(j = 0; j < 10; j++) {
            if(i == 0 || j == 0) arr[i][j] = 1;
        }
    }

    for(i = 1; i < 1001; i++) {
        for(j = 1; j < 10; j++) {
            arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % 10007;
        }
    }

    printf("%d", arr[n][9]);

    return 0;
}