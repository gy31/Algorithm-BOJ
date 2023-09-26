#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int map[50][50];
int nx[4] = {-1, 1, 0, 0}, ny[4] = {0, 0, -1, 1};
int M, N, K;
void bfs(int a, int b) {
    int x, y;
    pair <int, int> t;
    queue <pair<int,int>> q;
    q.push(make_pair(a, b));
    map[a][b] = 0;
    while(!q.empty()) {
        t = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            x = t.first + nx[i]; y = t.second + ny[i];
            if(x < 0 || x >= 50 || y < 0 || y >= 50) continue;
            if(!map[x][y]) continue;
            q.push(make_pair(x, y));
            map[x][y] = 0;
        }
    }
}
int main() 
{
    int T, a, b;

    scanf("%d", &T);

    while(T--) {
        int cnt = 0;
        scanf("%d%d%d", &M, &N, &K);
        for(int i = 0; i < K; i++) {
            scanf("%d%d", &a, &b);
            map[a][b] = 1;
        }
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(map[i][j]) {
                    bfs(i, j); cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }


    return 0;
}