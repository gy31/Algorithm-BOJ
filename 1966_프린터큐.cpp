#include<stdio.h>
#include<queue>
using namespace std;
int T, N, M;
int main() {
    scanf("%d", &T);

    while(T--) {
        int cnt = 0;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        scanf("%d%d", &N, &M);
        for(int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            q.push({a, i});
            pq.push(a);
        }
        while(!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            if(t.first == pq.top()) {
                pq.pop(); cnt++;
                if(t.second == M) {
                    printf("%d\n", cnt);
                    break;
                }
            }
            q.push(t);
        }
    }

    return 0;
}