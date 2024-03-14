#define INF 100000000
#define MA 101
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, arr[MA][MA], route[MA][MA];
vector<int> path;
void find(int st, int ed) {
    int x = route[st][ed];

    while(x != 0) {
        path.push_back(x);
        x = route[st][x];
    }
}
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
        arr[a][b] = min(arr[a][b], c);
        route[a][b] = a;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(arr[i][j] > arr[i][k] + arr[k][j]) route[i][j] = route[k][j];
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(arr[i][j] == INF) printf("0 ");
            else printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) printf("0\n");
            else {
                find(i, j);
                if(path.empty() && arr[i][j] == INF) printf("0");
                else {
                    printf("%d ", path.size()+1);
                    for(int i = 1; i <= path.size(); i++) {
                        printf("%d ", path[path.size() - i]);
                    }
                    printf("%d ", j);
                }
                printf("\n");
            }
            path.clear();
        }
    }

    return 0;
}