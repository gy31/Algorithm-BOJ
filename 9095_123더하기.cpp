#include<stdio.h>
int arr[12] = {1,};
int main()
{
    int i, j, n, t;
    scanf("%d", &t);

    for(i = 1; i <= 11; i++) {
        for(j = i - 3; j < i; j++){
            if(j < 0) continue;
            arr[i] += arr[j];
        }
    }
    
    for(i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", arr[n]);
    }

    return 0;
}