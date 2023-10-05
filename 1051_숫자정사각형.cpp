#include<stdio.h>
int main() {
    int i, j, k, n, m, max, cnt = 0, ans = 0;
    int num[50][50];

    scanf("%d%d", &n, &m);

    n >= m ? max = m : max = n;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%1d", &num[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            int tmp = num[i][j];
            for(k = 0; k < max; k++) {
                if(i+k >= n || j+k >= m) break;
                if(tmp == num[i+k][j] && tmp == num[i][j+k] && tmp == num[i+k][j+k]) {
                    cnt = (k+1) * (k+1);
                }
                if(cnt > ans) ans = cnt;
            }
        }
    }

    printf("%d", ans);

    return 0;
}