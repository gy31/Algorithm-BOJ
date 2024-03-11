#define INF 100000000
#define MA 501
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int TC;
struct tmp {
    int S, E, T;
};
int main() {
    scanf("%d", &TC);

    while(TC--) {
        int flag = 0, dis[MA], N, M, W;
        vector<tmp> v;
        scanf("%d%d%d", &N, &M, &W);

        for(int i = 0; i < M; i++) {
            int S, E, T;
            scanf("%d%d%d", &S, &E, &T);
            v.push_back({S, E, T});
            v.push_back({E, S, T});
        }

        for(int i = 0; i < W; i++) {
            int S, E, T;
            scanf("%d%d%d", &S, &E, &T);
            v.push_back({S, E, -T});
        }

        for(int i = 0; i <= N; i++) {
            dis[i] = INF;
        }

        for(int i = 1; i < N; i++) {
            for(int j = 0; j < v.size(); j++) {
                if(dis[v[j].E] > dis[v[j].S] + v[j].T) {
                    dis[v[j].E] = dis[v[j].S] + v[j].T;
                }
            }
        }

        for(int i = 0; i < v.size(); i++) {
            if(dis[v[i].E] > dis[v[i].S] + v[i].T) {
                flag = 1;
                break;
            }
        }

        if(flag) printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}