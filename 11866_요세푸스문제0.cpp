#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<int> q;
vector<int> v;
int main() {
    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        q.push(i);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            int t = q.front();
            q.pop();
            if(j == K) {
                v.push_back(t);
                continue;
            }
            q.push(t);
        }
    }
    cout << "<";
    for(int i = 0; i < N-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[N-1] << ">";

    return 0;
}