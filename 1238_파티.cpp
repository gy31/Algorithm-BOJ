#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v[1001];
int N, M, X;
int dijkstra(int st, int ed) {
    vector<int> dist(N+1, 1000000000);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, st));
    dist[st] = 0;
    while(!pq.empty()) {
        int x, y;
        pair<int, int> t = pq.top();
        pq.pop();
        x = t.second;
        y = t.first*-1;

        if(dist[x] < y) continue;

        for(int i = 0; i < v[x].size(); i++) {
            int next = v[x][i].first;
            int next_y = v[x][i].second + y;
            if(dist[next] > next_y) {
                dist[next] = next_y;
                pq.push(make_pair(next_y*-1, next));
            }
        }
    }
    return dist[ed];
}
int main() {
    int i, answer = 0;
    scanf("%d%d%d", &N, &M, &X);

    for(i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v[a].push_back({b,c});
    }

    for(i = 1; i <= N; i++) {
        int x, y;
        x = dijkstra(i, X);
        y = dijkstra(X, i);
        answer = max(answer, x+y);
    }

    printf("%d", answer);

    return 0;
}