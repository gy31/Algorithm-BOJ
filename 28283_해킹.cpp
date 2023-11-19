#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> A = {0,};
vector<int> map[500001];
int chk[500001];
priority_queue<long long> pq;
queue<int> q;
long long answer;
int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i = 0; i < Y; i++) {
        int a;
        cin >> a;
        q.push(a);
        chk[a] = 1;
    }

    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 0; i < map[t].size(); i++) {
            if(chk[map[t][i]] != 0) continue;
            chk[map[t][i]] = chk[t] + 1;
            q.push(map[t][i]);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(chk[i] == 0 && map[i].size() != 0) {
            cout << -1;
            return 0;
        }
    }

    for(int i = 1; i <= N; i++) {
        long long a = (chk[i] - 1) * A[i];
        pq.push(a);
    }

    for(int i = 1; i <= X; i++) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
    

    return 0;
}