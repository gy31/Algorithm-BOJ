#include<stdio.h>
#include<algorithm>
using namespace std;
pair <int, int> p[100000];
int chk(pair <int, int> i, pair <int, int> j) {
    if(i.second == j.second) return i.first < j.first;
    return i.second < j.second;
}
int main()
{
    int i, n, cnt = 0, min;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }

    sort(p, p+n, chk);

    cnt += p[1].first - p[0].first + p[n-1].first - p[n-2].first;

    for(i = 1; i <= n-2; i++) {
        min = 100000;
        if(p[i].second == p[i+1].second && min > p[i+1].first - p[i].first) min = p[i+1].first - p[i].first;
        if(p[i-1].second == p[i].second && min > p[i].first - p[i-1].first) min = p[i].first - p[i-1].first;
        cnt += min;
    }

    printf("%d", cnt);

    return 0;
}