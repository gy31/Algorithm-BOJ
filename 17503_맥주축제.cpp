#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> likepq;
pair<int, int> beer[200000];
bool cmp(pair<int, int> i, pair<int, int> j) {
    return i.second < j.second;
}
int N, M, K, sum, answer;
int main() {
    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) {
        int like, level;
        cin >> like >> level;
        beer[i] = make_pair(like, level);
    }

    sort(beer, beer+K, cmp);

    // for(int i = 0; i < K; i++) {
    //     cout << beer[i].first << " " << beer[i].second << "\n";
    // }
    int t = 0;
    while(sum < M) {
        while(!likepq.empty()) {
            likepq.pop();
        }
        for(int i = t; i < K; i++) {
            if(likepq.size() < N) {
                likepq.push(beer[i].first);
                sum += beer[i].first;
                if(likepq.size() == N && sum >= M) {
                    cout << beer[i].second;
                    return 0;
                }
            }
            else if(likepq.size() == N) {
                sum -= likepq.top();
                likepq.pop();
                i--;
            }
        }
        t++;
        if(t == K) {
            cout << -1;
            return 0;
        }
    }

    return 0;
}