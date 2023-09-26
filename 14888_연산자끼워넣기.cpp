#include<stdio.h>
int n, min=1000000000, max=-1000000000;
int num[11], cnt[4];
void pro(int w, int x, int y, int z, int i, int sum) {
    if(i == n) {
        if(min > sum) min = sum;
        if(max < sum) max = sum;
        return;
    }
    
    if(w > 0) pro(w-1, x, y, z, i+1, sum+num[i]);
    if(x > 0) pro(w, x-1, y, z, i+1, sum-num[i]);
    if(y > 0) pro(w, x, y-1, z, i+1, sum*num[i]);
    if(z > 0) pro(w, x, y, z-1, i+1, sum/num[i]);
}
int main()
{
    int i;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for(i = 0; i < 4; i++) {
        scanf("%d", &cnt[i]);
    }

    pro(cnt[0], cnt[1], cnt[2], cnt[3], 1, num[0]);

    printf("%d\n%d", max, min);

    return 0;
}