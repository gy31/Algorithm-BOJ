#include<stdio.h>
int answer;
int main()
{
    int n, i;
    int tmp;
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        tmp = i;
        while (tmp > 0)
        {
            if((tmp % 10) % 3 == 0 && tmp % 10 != 0)
            {
                answer++;
            }
            tmp = tmp / 10;
        }
    }

    printf("%d", answer);

    return 0;
}