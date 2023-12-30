#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
vector<vector<int>> map;
int cnt = 1;
void dfs(int n) {
    v[n] = cnt++;
    for(int i = 0; i < map[n].size(); i++) {
        if(!v[map[n][i]]) dfs(map[n][i]);
    }
}
int main() {
    int N, M, R;
    cin >> N >> M >> R;

    map.resize(N+1);
    v.resize(N+1);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        sort(map[i].begin(), map[i].end());
    }

    dfs(R);

    for(int i = 1; i <= N; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}