#include<iostream>
using namespace std;
int map[50][50], chk[50][50], dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
int main() {
    int N, M, r, c, d, cnt = 0, nx, ny; // d: 0=북 1=동 2=남 3=서
    cin >> N >> M >> r >> c >> d;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while(1) {
        int dirty = 0;
        if(chk[r][c] == 0) {
            cnt++;
            chk[r][c] = 1;
        }
        for(int i = 0; i < 4; i++) {
            nx = r + dx[i];
            ny = c + dy[i];
            if(!chk[nx][ny] && !map[nx][ny]) dirty++;
        }
        if(dirty == 0) { // 청소되지 않은 빈 칸이 없는 경우
            nx = r + dx[(d+2) % 4];
            ny = c + dy[(d+2) % 4];
            if(map[nx][ny] == 0) {
                r = nx;
                c = ny;
            }
            else {
                cout << cnt;
                return 0;
            }
        }
        else { // 청소되지 않은 빈 칸이 있는 경우
            while(1) {
                d -= 1;
                if(d == -1) d = 3;
                nx = r + dx[d];
                ny = c + dy[d];
                if(!chk[nx][ny] && !map[nx][ny]) break;
            }
            r = nx;
            c = ny;
        }
    }

    return 0;
}