#include<iostream>
#include<queue>
using namespace std;
int map[1000][1000], zx[4]={1,-1,0,0}, zy[4]={0,0,1,-1};
queue<pair<int, int>> q;
int cnt, ans, M, N;
void bfs() {
    int x,y;
    pair<int,int> t;
    while(!q.empty()) {
        t = q.front();
        q.pop();
        x = t.first; y = t.second;
        ans = map[x][y] - 1;
        for(int i = 0; i < 4; i++) {
            int nx, ny;
            nx = x + zx[i];
            ny = y + zy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] != 0) continue;
            
            map[nx][ny] = map[x][y] + 1;
            q.push({nx, ny});
            cnt--;
        }
    }
}
int main() {
    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                q.push({i,j});
            }
            else if(map[i][j] == 0) {
                cnt++;
            }
        }
    }

    bfs();

    if(cnt != 0) ans = -1;
    cout << ans;

    return 0;
}