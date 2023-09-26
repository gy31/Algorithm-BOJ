#include<stdio.h>
int arr[1025][1025];
int main()
{
    int i, j, n, m, w, x, y, z, tmp = 0, answer;
    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            tmp += arr[i][j];
            arr[i][j] = tmp;
        }
    }

    for(i = 0; i < m; i++) {
        scanf("%d%d%d%d", &w, &x, &y, &z);
        if(x-1 < 1) answer = arr[y][z] - arr[w-1][n];
        else answer = arr[y][z] - arr[w][x-1];
        printf("%d\n", answer);
    }

    return 0;
}