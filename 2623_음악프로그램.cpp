#define MA 1001
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> map[MA];
vector<int> ans;
queue<int> q;
int N, M, cnt[MA], chk[MA];
int main() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int n;
        vector<int> arr;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        for(int j = 1; j < n; j++) {
            int a = arr[j-1];
            int b = arr[j];
            map[a].push_back(b);
            cnt[b]++;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(!cnt[i]) {
            q.push(i);
            ans.push_back(i);
            chk[i]++;
        }
    }

    while(!q.empty()) {
        int t = q.front(); q.pop();
        for(int i = 0; i < map[t].size(); i++) {
            cnt[map[t][i]]--;
            if(!cnt[map[t][i]]) {
                q.push(map[t][i]);
                ans.push_back(map[t][i]);
                chk[map[t][i]]++;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(!chk[i]) {
            cout << "0";
            return 0;
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}