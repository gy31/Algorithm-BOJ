#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int map[26][26], chk[26][26];
vector<int> answer;
int nx[4] = {0, 0, 1, -1}, ny[4] = {-1, 1, 0, 0};
int n, cnt = 0;
void dfs(int x, int y) {
    if(x >= n || y >= n || map[x][y] == 0) return;
    
    if(map[x][y] == 1) {
        chk[x][y] = cnt;
        map[x][y] = 0;
    }
    
    for (int i = 0; i < 4; i++)
    {
        dfs(x + nx[i], y + ny[i]);
    }

    return;
}
int main() {
    int i, j;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(map[i][j]) {
                ++cnt;
                answer.push_back(0);
                dfs(i,j);
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(chk[i][j]) {
                answer[chk[i][j]-1]++;
            }
        }
    }

    sort(answer.begin(), answer.end());

    printf("%d\n", cnt);
    for(i = 0; i < answer.size(); i++) {
        if(!answer[i]) continue;
        printf("%d\n", answer[i]);
    }

    return 0;
}