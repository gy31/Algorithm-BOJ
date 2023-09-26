#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> map[2000];
int n, m, chk[2001];
void dfs(int x, int depth) {
    if(depth >= 4) return;

    chk[x]++;
    for(int i = 1; i < map[x].size(); i++) {
        if(chk[map[x][i]]) continue;
        dfs(map[x][i], depth+1);
    }
    return;
}
int main()
{
    int i, x, y;
    scanf("%d%d", &n, &m);

    for(i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        map[x].push_back(y);
        map[y].push_back(x);
    }
    dfs(map[0][0], 1);
    printf("%d", 0);

    return 0;
}