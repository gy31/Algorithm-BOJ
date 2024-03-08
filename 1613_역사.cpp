#define INF 100000000
#define MA 401
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, K, S, arr[MA][MA];
int main() {
    scanf("%d%d", &N, &K);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 1; i <= K; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        arr[a][b] = 1;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    scanf("%d", &S);

    for(int i = 0; i < S; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        if(arr[a][b] == INF && arr[b][a] == INF) printf("0\n");
        else if(arr[a][b] > 0 && arr[b][a] == INF) printf("-1\n");
        else if(arr[a][b] == INF && arr[b][a] > 0) printf("1\n");
    }

    return 0;
}