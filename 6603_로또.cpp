#include<stdio.h>
int s[13], num[6], chk[50];
int k;
void pro(int n, int p) {
    if(n == 6) {
        for(int i = 0; i < 6; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
    }

    for(int i = p; i <= k; i++) {
        if(!chk[s[i]]) {
            chk[s[i]]++;
            num[k] = s[i];
            pro(k+1, i+1);
            chk[s[i]] = 0;
        }
    }
}
int main()
{
    int i;

    while(1) {
        scanf("%d", &k);
        if(k == 0) break;

        for(i = 0; i < k; i++) {
            scanf("%d", &s[i]);
        }

        pro(0, 0);
        printf("\n");
    }

    return 0;
}