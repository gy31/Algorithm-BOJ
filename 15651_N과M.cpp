#include<stdio.h>
int n, m;
int dab[7];
void pro(int k) {
    if(k == m) {
        for(int i = 0; i < k; i++) {
            printf("%d ", dab[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++) {
        dab[k] = i;
        pro(k+1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    pro(0);
   
    return 0;
}