#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> map[100001];
int chk[100001], parent[100001];
void dfs(int x) {
    for(int i = 0; i < map[x].size(); i++) {
        if(!chk[map[x][i]]) {
            chk[map[x][i]] = 1;
            parent[map[x][i]] = x;
            dfs(map[x][i]);
        }
    }


}
int main() {
    cin >> N;

    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    dfs(1);

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}