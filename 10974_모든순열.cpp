#include<stdio.h>
int n, cnt;
int chk[9], num[4];
void back(int m) {
    int i;
    if(m > n) {
        for(i = 1; i <= n; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }

    for(i = 1; i <= n; i++) {
        if(!chk[i]) {
            num[m] = i;
            chk[i] = 1;
            back(m+1);
            chk[i] = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    back(1);

    return 0;
}