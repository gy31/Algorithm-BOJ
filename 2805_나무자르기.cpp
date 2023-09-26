#include<stdio.h>
int tree[1000000];
int main()
{
    int i, n, m, low, high, mid, answer = 0;
    long long cnt;
    scanf("%d%d", &n, &m);

    for(i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    low = 1; high = 1000000000;

    while(low <= high) {
        mid = (low+high) / 2;
        cnt = 0;
        for(i = 0; i < n; i++) {
            if(tree[i] > mid)
                cnt += (tree[i] - mid);
        }

        if(cnt < m) high = mid - 1;
        else if(cnt >= m) {
            answer = mid;
            low = mid + 1;
        }

    }

    printf("%d", answer);

    return 0;
}