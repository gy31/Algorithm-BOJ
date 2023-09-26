#include<stdio.h>
char map[5][5];
int chk[5][5];
void dfs(int x, int y) {
    if(x < 0 || x >= 5 || y < 0 || y >= 5) return;
    if(!chk[x][y]) return;
    chk[x][y] = 0;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}
void choice(int Y, int S) {
    if(Y+S == 7) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(chk[i][j]) dfs(i, j);
            }
        }
    }
    if(Y > 3) return;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(chk[i][j]) continue;
            chk[i][j] = 1;
            if(map[i][j] == 'Y') choice(Y+1, S);
            else choice(Y, S+1);
            chk[i][j] = 0;
        }
    }
}
int main()
{
    int i, j;
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%c", &map[i][j]);
        }
    }

    choice(0, 0);

    return 0;
}