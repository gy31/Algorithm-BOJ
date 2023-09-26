#include<stdio.h>
int n, m;
int dab[10], chk[10];
void pro(int k) {
    if(k == m) {
        for(int i = 0; i < k; i++) {
            printf("%d ", dab[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(chk[i] == 0) {
            chk[i]++;
            dab[k] = i;
            pro(k+1);
            chk[i] = 0;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    pro(0);
   
    return 0;
}