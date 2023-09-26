#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int, vector<int, pair<int, int>>> pq;
vector<int> lst;
queue<pair<int, int>> q;
int zx[4] = {0, 0, -1, 1}, zy[4] = {-1, 1, 0, 0};
int map[20][20], cmap[20][20], st[400][2], ed[400][2];
int n;
void bfs(int x, int y) {
    fill(cmap[0], cmap[20], 0);
    int i, j, cnt = 1;
    int nx, ny;
    pair<int, int> t;
    cmap[x][y] = cnt++;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        t = q.front();
        q.pop();
        for(i = 0; i < 4; i++) {
            nx = t.first + zx[i]; ny = t.second + zy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny]) continue;
            cmap[nx][ny] = cnt++;
            q.push(make_pair(nx, ny));
        }
    }
}
int main() {
    int i, j, m, energy;
    int taxi_x, taxi_y;

    scanf("%d%d%d", &n, &m, &energy);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    scanf("%d%d", &taxi_x, &taxi_y);

    for(i = 0; i < m; i++) {
        scanf("%d%d%d%d", &st[i][0], &st[i][1], &ed[i][0], &ed[i][1]);
    }

    bfs(taxi_x, taxi_y);
    for(i = 0; i < m; i++) {
        pq.push(cmap[st[i][0]][st[i][1]], make_pair(st[i][0], st[i][1]));
    }

    return 0;
}