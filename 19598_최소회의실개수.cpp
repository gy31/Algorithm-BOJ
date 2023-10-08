#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int, int> p[100000];
int cmp(pair<int, int> i, pair<int, int> j) {
    return i.second < j.second || i.first < j.first;
}
int main() {
    int i, n, x, y, cnt = 0, answer = 0;

    scanf("%d", &n);
    answer = n;

    for(i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        p[i] = make_pair(x, y);
    }

    sort(p, p+n, cmp);

    for(i = 0; i < n-1; i++) {
        if(p[i].second <= p[i+1].first) cnt++;
        else {
            answer -= cnt;
            cnt = 1;
        }
    }

    if(cnt == n-1) answer = 1;
    printf("%d", answer);

    return 0;
}