#define MA 10001
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K, cost[MA], v[MA], chk[MA], ans;
int find(int x) {
    if(v[x] == x) return v[x];
    return v[x] = find(v[x]);
}
int main() {
    int flag = 0;
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
        cin >> cost[i];
        v[i] = i;
    }

    for(int i = 1; i <= M; i++) {
        int a, b, x, y;
        cin >> a >> b;
        x = find(a);
        y = find(b);
        if(x != y) {
            if(cost[x] > cost[y]) v[x] = y;
            else v[y] = x;
        }
    }

    for(int i = 1; i <= N; i++) {
        int a;
        a = find(i);
        if(!chk[a]) {
            ans += cost[a];
            chk[a] = 1;
        }
    }

    if(ans > K) cout << "Oh no";
    else cout << ans;

    return 0;
}