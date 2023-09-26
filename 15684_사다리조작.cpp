#include<stdio.h>
#include<algorithm>
using namespace std;
int cmp(int i, int j) {
    return arr[i][0] < arr[j][0] || arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1];
}
int arr[300][2];
int n, m, h;
void pro(int a, int b, int cnt) {
    
}
int main()
{
    int i;
    scanf("%d%d%d", &n, &m, &h);

    for(i = 0; i < m; i++) {
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }

    sort(arr, arr+m);

    pro(0, 0, 0);

    return 0;
}