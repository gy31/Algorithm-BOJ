#include<stdio.h>
#include<algorithm>
using namespace std;
int chk(pair <int, int> i, pair <int, int> j) {
    return i.second < j.second || i.second == j.second && i.first < j.first;
}
pair <int, int> p[100001];
int main()
{
    int i, j, n, tmp, cnt = 1;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }

    sort(p, p+n, chk);

    tmp = p[0].second;
    for(i = 1; i < n; i++) {
        if(p[i].first >= tmp) {
            cnt++;
            tmp = p[i].second;
        } 
    }

    printf("%d", cnt);

    return 0;
}