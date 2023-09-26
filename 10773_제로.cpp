#include<stdio.h>
int stack[100001];
int main()
{
    int i, k, tmp, sum = 0, key = -1;
    scanf("%d", &k);
    
    for(i = 0; i < k; i++) {
        scanf("%d", &tmp);
        if(tmp == 0) key--;
        else stack[++key] = tmp;
    }

    for(i = 0; i <= key; i++) {
        sum += stack[i];
    }

    printf("%d", sum);

    return 0;
}