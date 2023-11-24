#include<iostream>
#include<queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long>> pq;
int main() {
    int n, m;
    long long answer = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    for(int i = 0; i < m; i++) {
        long long x, y;
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        pq.push(x+y); pq.push(x+y);
    }

    for(int i = 0; i < n; i++) {
        answer += pq.top(); pq.pop();
    }

    cout << answer;

    return 0;
}