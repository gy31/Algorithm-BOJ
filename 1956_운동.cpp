#define INF 100000000
#define MA 401
#include<stdio.h>
#include<algorithm>
using namespace std;
int V, E, arr[MA][MA], ans = INF;
int main() {
    scanf("%d%d", &V, &E);

    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 1; i <= E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        arr[a][b] = c;
    }

    for(int k = 1; k <= V; k++) {
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            if(arr[i][j] == INF || i == j) continue;
            ans = min(ans, arr[i][j] + arr[j][i]);
        }
    }

    if(ans == INF) printf("-1");
    else printf("%d", ans);

    return 0;
}