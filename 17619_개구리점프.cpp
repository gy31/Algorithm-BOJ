#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct tmp{
    int x, st, seq;
};
int N, Q;
vector<tmp> X;
vector<int> group;
bool cmp(tmp i, tmp j) {
    if(i.x == j.x) return i.st > j.st;
    return i.x < j.x;
}
int find(int x) {
    if(x == group[x]) return group[x];
    group[x] = find(group[x]);
    return group[x];
}
int main() {
    int ans, cnt = 0;
    scanf("%d%d", &N, &Q);

    for(int i = 0; i < N; i++) {
        int x1, x2, y;
        scanf("%d%d%d", &x1, &x2, &y);
        X.push_back({x1, 1, i+1});
        X.push_back({x2, -1, i+1});
        group.push_back(i);
    }
    group.push_back(N);

    sort(X.begin(), X.end(), cmp);

    for(int i = 0; i < X.size(); i++) {
        if(cnt > 0) {
            int a, b;
            a = find(X[i-1].seq);
            b = find(X[i].seq);
            if(a != b) group[b] = a;
        }
        cnt += X[i].st;
    }

    for(int i = 0; i < Q; i++) {
        int st, ed, a, b;
        scanf("%d%d", &st, &ed);
        a = find(st);
        b = find(ed);
        if(a == b) ans = 1;
        else ans = 0;
        printf("%d\n", ans);
    }

    return 0;
}