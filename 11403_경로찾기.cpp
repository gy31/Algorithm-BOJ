#define INF 100000000
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, arr[101][101];
int main() {
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int a;
            scanf("%d", &a);
            if(a == 1) arr[i][j] = a;
        }
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(arr[i][j] == INF || arr[i][j] == 0) printf("0 ");
            else if(arr[i][j] > 0) printf("1 ");
        }
        printf("\n");
    }

    return 0;
}