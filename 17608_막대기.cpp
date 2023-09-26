#include<stdio.h>
int stick[100000];
int main()
{
    int n, i, h, key = -1;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &h);
        while(stick[key] <= h) {
            if(key == -1) break;
            key--;
        }
        stick[++key] = h;
    }

    printf("%d", key+1);

    return 0;
}