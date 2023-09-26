#include<stdio.h>
int num[20];
int n, s, cnt;
void pro(int i, int sum) {
    if(i == n) return;
    if(sum == s) cnt++;

    pro(i+1, sum+num[i+1]-num[i]);
    pro(i+1, sum+num[i+1]);
    
}
int main()
{
    int i;
    scanf("%d%d", &n, &s);

    for(i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    pro(0, num[0]);
    
    printf("%d", cnt);

    return 0;
}