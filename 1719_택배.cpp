#define INF 100000000
#define MA 201
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, arr[MA][MA], path[MA][MA];
int main() {
    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        arr[a][b] = arr[b][a] = c;
        path[a][b] = b;
        path[b][a] = a;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(arr[i][k] + arr[k][j] < arr[i][j]) path[i][j] = path[i][k];
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) printf("- ");
            else printf("%d ", path[i][j]);
        }
        printf("\n");
    }

    return 0;
}