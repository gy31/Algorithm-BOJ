#include<stdio.h>
int arr[1000][1000];
int main()
{
    int i, j, c, r, k, cnt = 1;
    scanf("%d%d%d", &c, &r, &k);
    
    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++) {
            arr[i][j] = cnt++;
            
        }
    }

    if(k > c*r) printf("0");
    else printf("%d %d", i, j);

    return 0;
}