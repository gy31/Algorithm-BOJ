#include<iostream>
using namespace std;
int N, M, ans, V[1001], dis[1001][1001];
char c[1001];
int find(int x) {
    if(x == V[x]) return V[x];
    return V[x] = find(V[x]);
}
int main() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> c[i];
        V[i] = i;
    }

    for(int i = 1; i <= M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if(c[u] != c[v]) {
            int a, b;
            a = find(u);
            b = find(v);
            if(a != b) {
                V[b] = a;
                dis[u][v] = dis[v][u] = d;
            }
            else if(dis[u][v] != 0 && d < dis[u][v]) {
                dis[u][v] = dis[v][u] = d;
            }
        }
    }

    for(int i = 2; i <= N; i++) {
        if(find(V[i-1]) != find(V[i])) {
            cout << -1;
            return 0;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(dis[i][j] != 0) {
                ans += dis[i][j];
            }
        }
    }

    cout << ans;

    return 0;
}