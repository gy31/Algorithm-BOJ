#include<stdio.h>
int arr1[5], arr2[5];
int main()
{
    int n, a, b, tmp;
    int i, j;

    scanf("%d", &n);
    
    for (j = 0; j < n; j++)
    {
        for (i = 0; i <= 4; i++) arr1[i] = arr2[i] = 0; // 초기화

        scanf("%d", &a);

        for ( i = 0; i < a; i++)
        {
            tmp = 0;
            scanf("%d", &tmp);
            arr1[tmp]++;
        }

        scanf("%d", &b);
        
        for ( i = 0; i < b; i++)
        {
            tmp = 0;
            scanf("%d", &tmp);
            arr2[tmp]++;
        }

        for (i = 4; i > 0; i--)
        {
            if (arr1[i] > arr2[i])
            {
                printf("A\n");
                break;
            }
            else if (arr2[i] > arr1[i])
            {
                printf("B\n");
                break;
            }

            if (i == 1) printf("D\n");
        }
        
    }
    
    

    return 0;
}