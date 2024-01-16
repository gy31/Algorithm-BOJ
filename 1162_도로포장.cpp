#define INF 1000000001
#define MAX 10001
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K, s, e;
int chk[MAX], dis[MAX];
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
void dijk() {
    fill(chk, chk+MAX, 0);
    fill(dis, dis+MAX, INF);
    dis[1] = 0;
    q.push({0,1});

    while(!q.empty()) {
        int x = q.top().second;
        int y = q.top().first;
        q.pop();
        if(chk[x]) continue;
        chk[x] = 1;
        for(int i = 0; i < v[x].size(); i++) {
            int nxt = v[x][i].first;
            if(x == s && nxt == e || x == e && nxt) continue;
            // 포장안함
            if(dis[nxt] > dis[x] + v[x][i].second) {
                dis[nxt] = dis[x] + v[x][i].second;
                q.push({dis[nxt], nxt});
            }
            // 포장함
            if(dis[nxt] > dis[x]) {
                dis[nxt] = dis[x];
                q.push({dis[nxt], nxt});
            }
        }
    }
}
int main() {
    int ans = INF;
    scanf("%d%d%d", &N, &M, &K);

    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dijk();

    for(int i = 0; i <= K; i++) {
        ans = min(ans, dis[N]);
    }

    printf("%d", ans);


    return 0;
}