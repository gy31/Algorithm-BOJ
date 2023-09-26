#include<stdio.h>
#include<stdlib.h>
int n, max;
int num[8], A[8], chk[8];
void pro(int k) {
    if(k == n) {
        int sum = 0;
        for(int i = 0; i < n-1; i++) {
            sum += abs(A[i] - A[i+1]);
        }
        if(sum > max) max = sum;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(chk[i] == 0) {
            chk[i]++;
            A[k] = num[i];
            pro(k+1);
            chk[i] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    pro(0);

    printf("%d", max);
   
    return 0;
}