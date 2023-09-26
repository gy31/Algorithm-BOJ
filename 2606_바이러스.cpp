#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> map[101];
int n, s, chk[101], answer;
void dfs(int x) {
    chk[x]++; answer++;
    for(int i = 0; i < map[x].size(); i++) {
        if(chk[map[x][i]]) continue;
        dfs(map[x][i]);
    }
}
int main()
{
    int i, x, y;
    scanf("%d%d", &n, &s);

    for(i = 0; i < s; i++) {
        scanf("%d%d", &x, &y);
        map[x].push_back(y);
        map[y].push_back(x);
    }

    dfs(1);
    printf("%d", answer-1);

    return 0;
}