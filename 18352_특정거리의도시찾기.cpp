#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[300001];
int chk[300001], cntArr[300001];
int N, M, K, X;
void bfs() {
    queue<int> q;
    int cnt = 1;
    chk[X] = 1;
    q.push(X);
    while(!q.empty()) {
        int s = q.size();
        while(s-- > 0) {
            int t = q.front(); q.pop();
            for(int i = 0; i < v[t].size(); i++) {
                int n = v[t][i];
                if(!chk[n]) {
                    q.push(n);
                    cntArr[n] = cnt;
                    chk[n] = 1;
                }
            }
        }
        cnt++;
    }
    return;
}
int main() {
    int flag = 0;
    cin >> N >> M >> K >> X;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    bfs();

    for(int i = 1; i <= N; i++) {
        if(cntArr[i] == K) {
            cout << i << "\n";
            flag = 1;
        }
    }

    if(flag == 0) cout << -1;

    return 0;
}