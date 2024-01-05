#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int> i, pair<int, int> j) {
    if(i.first == j.first) return i.second > j.second;
    else return i.first < j.first;
}
priority_queue<int, vector<int>, less<int>> pq;
vector<pair<int, int>> jewel;
vector<int> bag;
int main() {
    int N, K;
    long long int ans = 0;
    scanf("%d%d", &N, &K);

    for(int i = 0; i < N; i++) {
        int M, V;
        scanf("%lld%lld", &M, &V);
        jewel.push_back({M, V});
    }

    for(int i = 0; i < K; i++) {
        int C;
        scanf("%d", &C);
        bag.push_back(C);
    }
    sort(jewel.begin(), jewel.end(), cmp);
    sort(bag.begin(), bag.end());

    for(int i = 0, j = 0; i < K; i++) {
        while(j < N) {
            int m = jewel[j].first;
            int v = jewel[j].second;
            if(bag[i] >= m) {
                pq.push(v);
            }
            else break;
            j++;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    printf("%lld", ans);

    return 0;
}