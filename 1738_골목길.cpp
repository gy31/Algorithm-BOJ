#define INF -100000000
#define MA 101
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct tmp {
    int u, v, w;
};
vector<tmp> V;
vector<int> R[MA];
queue<int> Q;
int N, M, dis[MA], flag, arr[MA], chk[MA];
void back(int n) {
    if(n == 0) return;
    back(arr[n]);
    printf("%d ", n);
}
int main() {
    scanf("%d%d", &N, &M);

    fill(dis + 2, dis + N + 1, INF);
    Q.push(N); chk[N] = 1;

    for(int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        V.push_back({u, v, w});
        R[v].push_back(u);
    }

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int i = 0; i < R[cur].size(); i++) {
            if(!chk[R[cur][i]]) {
                chk[R[cur][i]] = 1;
                Q.push(R[cur][i]);
            }
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < V.size(); j++) {
            if(dis[V[j].u] == INF) continue;
            if(dis[V[j].v] < dis[V[j].u] + V[j].w) {
                dis[V[j].v] = dis[V[j].u] + V[j].w;
                arr[V[j].v] = V[j].u;
            }
        }
    }

    for(int i = 0; i < V.size(); i++) {
        if(chk[V[i].u] && dis[V[i].v] < dis[V[i].u] + V[i].w) flag = 1;
    }

    if(flag || dis[N] == INF) printf("-1");
    else back(N);

    return 0;
}