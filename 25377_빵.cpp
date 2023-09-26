#include<stdio.h>
int main()
{
    int n, a, b, answer = 9999;
    int i;
    
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        if(b  < answer && b - a >= 0)
            answer = b;
    }

    if(answer == 9999)
        answer = -1;

    printf("%d", answer);

    return 0;
}