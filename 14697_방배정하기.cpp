#include<stdio.h>
int answer;
int main()
{
    int a, b, c, n;
    int i, j, k;
    scanf("%d%d%d%d", &a, &b, &c, &n);

    for (i = n / a; i >= 0; i--)
    {
        for (j = n / b; j >= 0; j--)
        {
            for (k = n / c; k >= 0; k--)
            {
                if ((a * i) + (b * j) + (c * k) == n)
                {
                    answer = 1;
                    break;
                }
                
            }
        }
        
    }

    printf("%d", answer);

    return 0;
}