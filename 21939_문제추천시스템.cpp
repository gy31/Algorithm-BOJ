#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
vector<pair<int, int>> v;
int main() {
    int N, M;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        pq1.push(v[i]);
        pq2.push(v[i]);
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        char c[10];
        cin >> c;
        if(c == "add") {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
            pq1.push(v[i+N]);
            pq2.push(v[i+N]);
        }
        else if(c == "recommend") {
            int a;
            cin >> a;
            if(a == 1) {
                cout << pq1.top().first << "\n";
            }
            else if(a == -1) {
                cout << pq2.top().first << "\n";
            }
        }
        else if(c == "solved") {
            int a;
            cin >> a;
            
        } 
    }

    return 0;
}