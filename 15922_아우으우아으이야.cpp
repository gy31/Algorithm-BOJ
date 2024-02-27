#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<pair<int, int>> line;
bool cmp(pair<int, int> i, pair<int, int> j) {
    if(i.first == j.first) return i.second > j.second;
    return i.first < j.first;
}
int main() {
    int ans = 0, cnt = 0, x;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        line.push_back({a, 1});
        line.push_back({b, -1});
    }

    sort(line.begin(), line.end(), cmp);

    for(int i = 0; i < line.size(); i++) {
        if(line[i].second == 1) {
            if(cnt == 0) x = line[i].first;
            cnt++;
        }
        else {
            cnt--;
            if(cnt == 0) ans += line[i].first - x;
        }
    }

    printf("%d", ans);

    return 0;
}