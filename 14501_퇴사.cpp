#include<stdio.h>
int arr[15][2];
int n, max = 0;
void pro(int day, int m) {
    if(day >= n) {
        if(m > max) max = m;
        return;
    }
    pro(day + 1, m); // 상담 안함
    if(day + arr[day][0] <= n)
        pro(day + arr[day][0], m + arr[day][1]); // 상담 함
}
int main() {
    int i, t, p;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }

    pro(0,0);

    printf("%d", max);
    return 0;
}