#define INF 100000000
#define MA 101
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, arr[MA][MA];
int main() {
    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
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

    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(arr[i][j] != INF && arr[i][j] != 0) cnt++;
            if(arr[j][i] != INF && arr[j][i] != 0) cnt++;
        }
        printf("%d\n", N - cnt - 1);
    }

    return 0;
}