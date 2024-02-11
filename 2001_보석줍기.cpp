#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int N, M, K, jewel[101], visited[101][1<<15];
vector<pair<int, int>> map[101];
void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
}
int main() {
    scanf("%d%d%d", &N, &M, &K);

    for(int i = 0; i < K; i++) {
        int a;
        scanf("%d", &a);
        jewel[a] = 1;
    }

    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }

    return 0;
}