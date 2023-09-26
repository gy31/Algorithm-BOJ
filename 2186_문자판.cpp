#include<stdio.h>
#include<string.h>
char board[100][100], dp[80][100][100], alp[81];
int main()
{
    int i, j, K, cnt, answer = 0;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    
    for(i = 0; i < n; i++) {
        for(j = 0 ; j < m; j++) {
            scanf("%c", &board[i][j]);
        }
    }
    scanf("%s", alp);

    for(i = 0; i < n; i++) {
        for(j = 0 ; j < m; j++) {
            if(board[i][j] == alp[0]) dp[0][i][j]++;
        }
    }

    for(cnt = 1; cnt <= strlen(alp); cnt++) {
        for(i = 0; i < n; i++) {
            for(j = 0 ; j < m; j++) {
                if(board[i][j] >= 1) {
                    for(K = -k; K <= k; K++) {
                        // 범위 설정해야함
                        if(i+K < 0 || i+K >= n || j+K < 0 || j+K >= m) continue;
                        if(dp[cnt][i+K][j] == alp[cnt]) dp[cnt][i+K][j]++;
                        if(dp[cnt][i][j+K] == alp[cnt]) dp[cnt][i][j+K]++;
                    }
                }
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0 ; j < m; j++) {
            answer += dp[strlen(alp)][i][j];
        }
    }

    printf("%d", answer);

    return 0;
}