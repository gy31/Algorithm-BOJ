#include<stdio.h>
#include<math.h>
int arr[200];
int main()
{
    int a, b, n, i, x, y, sum = 0;
    scanf("%d%d%d", &a, &b, &n); // 가로, 세로, 상점 개수

    i = 0;
    while(n--) {
        scanf("%d%d", &arr[i++], &arr[i++]); // 상점 위치
    }
    scanf("%d%d", &x, &y); // 동근 위치

    i = 0;
    while(n--) {
        if(arr[i] == arr[n*2]) {
            sum += abs(arr[i+1] - arr[n*2+1]);
        }
        else {
            
        }
    }

    return 0;
}