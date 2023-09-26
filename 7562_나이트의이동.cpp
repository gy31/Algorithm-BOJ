#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct temp{
    int x, y;
}t;
queue<temp> q;
int N, X, Y, answer = -1;
int zx[8] = {-2, -1, 1, 2, -2, -1, 1, 2}, zy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int map[300][300];
void bfs(int a, int b) {
    int nx, ny;
    // pair <int, int> p;
    // queue <pair<int,int>> q;
    q = queue<temp>();
    fill(map[0], map[300], 0);
    t.x = a; t.y = b;
    map[a][b] = 1;
    q.push(t);

    while(!q.empty()) {
        t = q.front(); q.pop();
        if(t.x == X && t.y == Y) {
            answer = map[X][Y]-1;
            break;
        }
        for(int i = 0; i < 8; i++) {
            nx = t.x + zx[i]; ny = t.y + zy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(map[nx][ny] != 0) continue;
            t.x = nx; t.y = ny;
            q.push(t);
            map[nx][ny] = map[a][b] + 1;
        }
    }
}
int main() 
{
    int T, a, b;
    scanf("%d", &T);

    while(T--) {
        scanf("%d%d%d%d%d", &N, &a, &b, &X, &Y);
        bfs(a, b);
        printf("%d\n", answer);
    }

    return 0;
}