#define MA 6000
#define INF 1000000000
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, flag;
long long int st[MA],ed[MA],t[MA],dis[MA/12+1];
int main() {
    scanf("%d%d", &N, &M);

    for(int i = 0; i < M; i++) {
        scanf("%lld%lld%lld", &st[i],&ed[i],&t[i]);
    }

    for(int i = 2; i <= N; i++) {
        dis[i] = INF;
    }

    for(int i = 1; i <= N; i++) {
        flag = 0;
        for(int j = 0; j < M; j++) {
            if(dis[st[j]] == INF) continue;
            if(dis[ed[j]] > dis[st[j]] + t[j]) {
                dis[ed[j]] = dis[st[j]] + t[j];
                flag = 1;
            }
        }
    }

    if(flag) printf("-1");
    else {
        for(int i = 2; i <= N; i++) {
            if(dis[i] == INF) printf("-1\n");
            else printf("%lld\n", dis[i]);   
        }
    }

    return 0;
}