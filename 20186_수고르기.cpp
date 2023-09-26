#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[5000];
int answer;
int main()
{
    int n, k, max = 0, tmp = 0;
    int i;

    scanf("%d%d", &n, &k);

    int cnt = n - 1;

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);

    for(i = 0; i < k; i++)
        answer += (arr[cnt--] - i);

    printf("%d", answer);

    return 0;
}