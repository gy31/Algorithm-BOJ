#define INF 1000000000
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, arr[110][110];
int main() {
    int ans, minSum = 99999;
    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        arr[a][b] = arr[b][a] = 1;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = 1; j <= N; j++) {
            sum += arr[i][j];
        }
        if(sum < minSum) {
            minSum = sum;
            ans = i;
        }
    }

    printf("%d", ans);

    return 0;
}