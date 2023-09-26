#include<stdio.h>
int arr[1001][1001];
int main()
{
    int n, a, b, x, y, cnt;
    int i, j, k;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        for(j = a; j < a+x; j++) {
            for(k = b; k < b+y; k++) {
                arr[j][k] = i + 1;
            }
        }
    }

    for(i = 0; i < n; i++) {
        cnt = 0;
        for(j = 0; j < 1001; j++) {
            for(k = 0; k < 1001; k++) {
                if(arr[j][k] == i + 1) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    

    return 0;
}