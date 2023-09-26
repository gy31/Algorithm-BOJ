#include<stdio.h>
int arr[250000];
int answer;
int main()
{
    int n, cnt = 1;
    int i;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        if (arr[i] == cnt) 
        {
            cnt++;
            continue;
        }
        answer++;   
    }

    printf("%d", answer);

    return 0;
}