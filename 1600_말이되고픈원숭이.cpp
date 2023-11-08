#include<iostream>
#include<queue>
using namespace std;
struct position {
    int x; int y; int k;
};
queue<position> q;
int K, W, H;
int map[201][201];
int check[201][201][31];
int hnx[8] = {-2,-1,1,2,-2,-1,1,2}, hny[8] = {-1,-2,-2,-1,1,2,2,1};
int nx[4] = {0,0,-1,1}, ny[4] = {-1,1,0,0};
void bfs(int x, int y, int horse) {
    q.push({x, y, horse});
    check[x][y][horse] = 1;
    while(!q.empty()) {
        int a, b, c;
        int nextX, nextY;
        a = q.front().x;
        b = q.front().y;
        c = q.front().k;
        q.pop();
        if(a == H && b == W) {
            cout << check[a][b][c] - 1;
            return;
        }
        if(c < K) {
            for(int i = 0; i < 8; i++) {
                nextX = a + hnx[i];
                nextY = b + hny[i];
                if(nextX < 1 || nextX > H || nextY < 1 || nextY > W) continue;
                if(map[nextX][nextY] == 0 && !check[nextX][nextY][c+1]) {
                    check[nextX][nextY][c+1] = check[a][b][c] + 1;
                    q.push({nextX, nextY, c+1});
                }
            }
        }
        for(int i = 0; i < 4; i++) {
            nextX = a + nx[i];
            nextY = b + ny[i];
            if(nextX < 1 || nextX > H || nextY < 1 || nextY > W) continue;
            if(map[nextX][nextY] == 0 && !check[nextX][nextY][c]) {
                check[nextX][nextY][c] = check[a][b][c] + 1;
                q.push({nextX, nextY, c});
            }
        }
    }
    cout << -1;
    return;
}
int main() {
    cin >> K >> W >> H;
    for(int i = 1; i <= H; i++) {
       for(int j = 1; j <= W; j++) {
            cin >> map[i][j];
       } 
    }

    bfs(1, 1, 0);

    return 0;
}