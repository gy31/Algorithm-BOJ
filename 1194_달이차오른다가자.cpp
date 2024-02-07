#define MA 51
#include<stdio.h>
#include<queue>
using namespace std;
struct temp {
    int key, x, y, cnt;
};
queue<struct temp> q;
int N, M, dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0}, ans, chk[1<<6][MA][MA];
char map[MA][MA];
int bfs(int a, int b) {
    q.push({0, a, b});
    chk[0][a][b] = 1;

    while(!q.empty()) {
        int k, x, y, cnt;
        temp t;
        t = q.front(); q.pop();
        k = t.key; x = t.x; y = t.y;

        if(map[x][y] == '1') {
            return chk[k][x][y]-1;
        }
        for(int i = 0; i < 4; i++) {
            int nk, nx, ny;
            nk = k;
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(chk[k][nx][ny]) continue;
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == '#') continue;
            if(map[nx][ny] >= 'A' && map[nx][ny] <= 'F' && !(nk & (1 << (map[nx][ny] - 'A')))) continue;
            if(map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
                nk |= (1 << (map[nx][ny] - 'a'));
            }
            if(chk[nk][nx][ny] == 0) {
                chk[nk][nx][ny] = chk[k][x][y] + 1;
                q.push({nk, nx, ny});
            }
        }
    }
    return -1;
}
int main() {
    int x, y;
    scanf("%d%d", &N, &M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == '0') {
                x = i; y = j;
            }
        }
    }

    printf("%d", bfs(x, y));

    return 0;
}