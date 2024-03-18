#include<stdio.h>
#include<vector>
using namespace std;
vector<pair<int, int>> egg;
int N, ans, cnt;
void hit(int n) {
    if(n == N) return;
    if(egg[n].first <= 0) hit(n+1);

    for(int i = 0; i < N; i++) {
        if(i == n || egg[i].first <= 0 || egg[n].first <= 0) continue;

        egg[i].first -= egg[n].second;
        egg[n].first -= egg[i].second;

        if(egg[i].first <= 0) cnt++;
        if(egg[n].first <= 0) cnt++;
        
        if(ans < cnt) ans = cnt;

        hit(n+1);

        if(egg[i].first <= 0) cnt--;
        if(egg[n].first <= 0) cnt--;
        egg[i].first += egg[n].second;
        egg[n].first += egg[i].second;
    }
}
int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int a, b; // 내구도, 무게
        scanf("%d%d", &a, &b);
        egg.push_back({a, b});
    }

    hit(0);

    printf("%d", ans);

    return 0;
}