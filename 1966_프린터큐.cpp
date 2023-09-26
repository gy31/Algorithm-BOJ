#include<stdio.h>
#include<algorithm>
using namespace std;
int printQ[10000], numQ[10000], arr[100];
int chk(int i, int j) {
    return i < j;
}
int main()
{
    int i, j, x, n, m, input = 0, out = 0, idx;
    scanf("%d", &x);

    for(i = 0; i < x; i++) {
        scanf("%d%d", &n, &m);
        for(j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            numQ[input] = arr[j]; // 숫자
            printQ[input] = input; // 순서
            input++;
        }
        sort(arr, arr + n, chk);

        idx = 0;
        while(1) {
            if(numQ[out] == arr[idx]) {
                if(printQ[out] == m) break;
                out++; idx++;
            }
            else {
                numQ[input] = numQ[out];
                printQ[input] = printQ[out];
                input++;
            }
        }
        printf("%d\n", idx);
    }
    

    return 0;
}