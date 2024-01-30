#define MA 10001
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> map[MA];
int n, ans;
int dfs(int k) {
    int ma, mb;
    ma = mb = 0;
    for(int i = 0; i < map[k].size(); i++) {
        int t = dfs(map[k][i].first) + map[k][i].second;
        if(t > ma) {
            mb = ma;
            ma = t;
        }
        else if(t > mb) mb = t;
    }
    ans = max(ans, ma+mb);
    return ma;
}
int main() {
    scanf("%d", &n);

    for(int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        map[a].push_back({b, c});
    }

    dfs(1);

    printf("%d", ans);

    return 0;
}