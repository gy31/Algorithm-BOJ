#define MA 101
#define INF 1000000000
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, map[MA][MA];
int main() {
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) map[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[a][b] = min(map[a][b], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(k == i || k == j) continue;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == INF) printf("0 ");
            else printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}