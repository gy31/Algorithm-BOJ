#define MA 1001
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T, N, K, W, cost[MA], cnt[MA], build[MA];
int main() {
    cin >> T;

    while(T--) { 
        vector<int> map[MA];
        queue<int> q;
        cin >> N >> K;

        for(int i = 1; i <= N; i++) {
            cin >> cost[i];
            build[i] = cost[i];
        }

        for(int i = 1; i <= K; i++) {
            int a, b;
            cin >> a >> b;
            map[a].push_back(b);
            cnt[b]++;
        }

        cin >> W;

        for(int i = 1; i <= N; i++) {
            if(!cnt[i]) q.push(i);
        }

        while(!q.empty()) {
            int t = q.front(); q.pop();
            for(int i = 0; i < map[t].size(); i++) {
                if(build[t] + cost[map[t][i]] > build[map[t][i]]) {
                    build[map[t][i]] = build[t] + cost[map[t][i]];
                }
                cnt[map[t][i]]--;
                if(!cnt[map[t][i]]) {
                    q.push(map[t][i]);
                }
            }
        }
        cout << build[W] << "\n";
    }

    return 0;
}