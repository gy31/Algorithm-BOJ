#define MA 1001
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> map[MA];
queue<int> q;
int N, M, cnt[MA], dp[MA], via[MA], chk[MA];
void back(int x) {
    if(chk[x]) {
        cout << x << " ";
        return;
    }
    chk[x] = 1;
    back(via[x]);
    cout << x << " ";
}
int main() {
    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b, c});
        via[i] = i;
    }

    q.push(1);

    while(!q.empty()) {
        int t = q.front(); q.pop();
        
        for(int i = 0; i < map[t].size(); i++) {
            int a = map[t][i].first;
            int b = map[t][i].second;
            if(dp[a] < dp[t] + b) {
                dp[a] = dp[t] + b;
                via[a] = t;
            }
            q.push(a);
        }

        if(t == 1 && dp[1] > 0) {
            cout << dp[1] << "\n";
            back(1);
            return 0;
        }
    }

    return 0;
}