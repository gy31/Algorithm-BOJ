#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> chkicken[50];
int map[50][50];
int n, m, a, b;
void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    if(map[x][y] == 1) {}
    if(map[x][y] == 2) {}
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}
int main()
{
    int i, j, cnt = 0;
    scanf("%d%d", &n, &m);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2) chkicken[i].push_back(j);
        }
    }

    dfs(0,0);

    printf("%d", cnt);

    return 0;
}