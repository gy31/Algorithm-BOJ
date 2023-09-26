#include<stdio.h>
int arr[100001];
int main()
{
    int i, n, m, a, b;
    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
    }

    for(i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", arr[b] - arr[a-1]);
    }

    return 0;
}