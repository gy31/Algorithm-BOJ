#include<stdio.h>
#include<algorithm>
using namespace std;
int t[100001];
int main()
{
    int i, n, m, low, high, mid, answer, cnt = 0;
    scanf("%d%d", &n, &m);

    for(i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    sort(t, t+n);
    low = 1; high = t[0] * m;

    while(low <= high) {
        mid = (low + high) / 2;
        cnt = 0;
        for(i = 0; i < n; i++) {
            cnt += mid / t[i];
        }
        
        if(cnt >= m) {
            answer = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    printf("%d", answer);

    return 0;
}