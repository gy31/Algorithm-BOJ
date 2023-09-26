#include<stdio.h>

int kids[1000000], chk[1000001];

int main() {
    int i, n, max = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &kids[i]);
        chk[kids[i]] = chk[kids[i]-1] + 1;
        if(chk[kids[i]] > max) max = chk[kids[i]];
    }

    printf("%d", n - max);
    return 0;
}