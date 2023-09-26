#include<stdio.h>
int arr[101], cnt;
int main()
{
    int n;
    int i;
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    while(true)
    {
        cnt = 0;

        for(i = 2; i <= n; i+=2)
        {
            arr[++cnt] = arr[i];
        }
        n = cnt;

        if (n = 1)
        {
            printf("%d", arr[1]);
            break;
        }
        
    }

    return 0;
}