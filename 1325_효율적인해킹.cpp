#include<iostream>
#include<vector>
using namespace std;
vector<int> v[10000];
int chk[10001], cntArr[10001], m = 0, cnt = 0;
int dfs(int x) {
    chk[x] = 1; cnt++;
    if(cnt > m) m = cnt;
    for(int i = 0; i < v[x].size(); i++) {
        if(!chk[v[x][i]]) dfs(v[x][i]);
    }
    return cnt;
}
int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        cnt = 0;
        fill(chk, chk+N+1, 0);
        if(!chk[i]) {
            cntArr[i] = dfs(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(cntArr[i] == m) cout << i << " ";
    }

    return 0;
}