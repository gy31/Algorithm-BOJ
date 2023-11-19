#include<iostream>
#include<queue>
using namespace std;
int main() {
    int T, K, x;
    long long answer;
    cin >> T;

    for(int i = 0; i < T; i++) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        cin >> K;
        answer = 0;
        for(int j = 0; j < K; j++) {
            cin >> x;
            pq.push(x);
        }
        while(pq.size() > 1) {
            long long a, b;
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            pq.push(a+b);
            answer += a+b;
        }
        cout << answer << "\n";
        pq.pop();
    }

    return 0;
}