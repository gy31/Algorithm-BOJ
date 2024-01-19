#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct map {
    int a, b, c;
} t;
vector<map> info;
bool cmp(map i, map j) {
    return i.c < j.c;
}
int N, M, ans, V[1010], cnt;
char c[1010];
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
        cin >> t.a >> t.b >> t.c;
        info.push_back(t);
    }

    sort(info.begin(), info.end(), cmp);

    for(int i = 1; i <= M; i++) {
        int u, v, d, a, b;
        u = info[i-1].a;
        v = info[i-1].b;
        d = info[i-1].c;
        if(c[u] == c[v]) continue;
        a = find(u);
        b = find(v);
        if(a != b) {
            V[b] = a;
            ans += d;
            cnt++;
        }
    }
    
    if(cnt == N-1) cout << ans;
    else cout << -1;

    return 0;
}