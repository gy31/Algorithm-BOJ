#define INF 100000000
#define MA 101
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, R, item[MA], map[MA][MA], ans;
int main() {
    scanf("%d%d%d", &N, &M, &R);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &item[i]);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) map[i][j] = INF;
        }
    }

    for(int i = 0; i < R; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[a][b] = map[b][a] = c;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        int tmp = 0;
        for(int j = 1; j <= N; j++) {
            if(map[i][j] <= M) tmp += item[j];
        }
        ans = max(ans, tmp);
    }

    printf("%d", ans);

    return 0;
}