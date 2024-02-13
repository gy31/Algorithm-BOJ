#include<stdio.h>
#include<vector>
using namespace std;
int N, M, K, jewel[101], visited[101][1<<15], ans;
vector<pair<int, int>> map[101];
void dfs(int cur, int b, int cnt) {
    visited[cur][b] = 1;
    if(cur == 1 && cnt > ans) {
        ans = cnt;
    }
    for(int i = 0; i < map[cur].size(); i++) {
        int next = map[cur][i].first;
        int limit = map[cur][i].second;
        if(cnt <= limit && !visited[next][b]) dfs(next, b, cnt);
        if(jewel[cur] && cnt < limit && !visited[next][b | (1 << jewel[cur])]) {
            dfs(next, b | (1 << jewel[cur]), cnt+1);
        }
    }

}
int main() {
    scanf("%d%d%d", &N, &M, &K);

    for(int i = 1; i <= K; i++) {
        int a;
        scanf("%d", &a);
        jewel[a] = i;
    }

    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }

    map[1].push_back({1, 14});
    dfs(1, 0, 0);

    printf("%d", ans);

    return 0;
}