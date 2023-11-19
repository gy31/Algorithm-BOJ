#include<iostream>
#include<vector>
using namespace std;
vector<vector<pair<int, int>>> map;
int chk[100001], rec[100001];
int N, st, ed, len;
int stop = 0;
void dfs(int level, int x) {
    if(stop) return;
    if(x == ed) {
        len = level;
        stop = 1;
    }

    for(int i = 0; i < map[x].size(); i++) {
        int next = map[x][i].first;
        if(!chk[next] && !stop) {
            chk[next] = 1;
            rec[level] = map[x][i].second;
            dfs(level + 1, next);
            chk[next] = 0;
        }
    }
}
int main() {
    int answer = 0, max = 0;
    cin >> N >> st >> ed;

    map.resize(N+1);
    for(int i = 0; i < N-1; i++) {
        int a, b, len;
        cin >> a >> b >> len;
        map[a].push_back({b, len});
        map[b].push_back({a, len});
    }

    chk[st] = 1;
    dfs(0, st);

    for(int i = 0; i < len; i++) {
        max = max < rec[i] ? rec[i] : max;
        answer += rec[i];
    }

    answer -= max;

    cout << answer;

    return 0;
}