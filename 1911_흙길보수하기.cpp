#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, L, ans, mod, cur;
vector<pair<int, int>> v;
bool cmp(pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
}
int main() {
    scanf("%d%d", &N, &L);

    for(int i = 0; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++) {
        if(v[i].first <= cur && cur <= v[i].second) {
            int x = (v[i].second - cur) / L;
            mod = (v[i].second - cur) % L;

            ans += x;
            cur += x * L;

            if(mod != 0) {
                ans++;
                cur += L;
            }
        }
        else if( cur < v[i].first) {
            cur = v[i].first;
            i--;
        }
    }

    printf("%d", ans);

    return 0;
}