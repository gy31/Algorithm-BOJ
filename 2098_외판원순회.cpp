#define INF 1000000000
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, map[16][16], dp[16][1<<16];
int back(int x, int chk) {
    if(chk == (1<<N)-1) return map[x][0]; // 전부 방문
    if(dp[x][chk] != 0) return dp[x][chk];

    dp[x][chk] = INF;
    for(int i = 0; i < N; i++) {
        if(chk & (1 << i) || map[x][i] == INF) continue;
        dp[x][chk] = min(dp[x][chk], back(i, chk | (1 << i)) + map[x][i]);
    }
    return dp[x][chk];
}
int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0) map[i][j] = INF;
        }
    }

    printf("%d", back(0, 1));

    return 0;
}