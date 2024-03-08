#define INF 1000000000
#define MA 501
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, arr[MA][MA], cnt[MA], ans;
int main() {
    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 1; i <= M; i++) {
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
        for(int j = 1; j <= N; j++) {
            if(arr[i][j] != INF && arr[i][j] != 0) {cnt[i]++; cnt[j]++;}
        }
    }

    for(int i = 1; i <= N; i++) {
        if(cnt[i] == N-1) ans++;
    }

    printf("%d", ans);

    return 0;
}

/*
    세로 방향 -> 나보다 큰 학생
    가로 방향 -> 나보다 작은 학생
    세로 + 가로 = N-1 이면 자신의 키가 몇 번째인지 판단 가능
*/