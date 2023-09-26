#include<stdio.h>
int n, m;
int dab[8];
void pro(int k, int p) {
    if(k == m) {
        for(int i = 0; i < k; i++) {
            printf("%d ", dab[i]);
        }
        printf("\n");
        return;
    }

    for(int i = p; i <= n; i++) {
        dab[k] = i;
        pro(k+1, i);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    pro(0, 1);
   
    return 0;
}