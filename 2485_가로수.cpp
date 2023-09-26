#include<stdio.h>
int tree[100000], arr[100000];
int main()
{
    int n, tmp, a, b, min = 999, cnt = 0;
    int i;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
        if(i >= 1) arr[i-1] = tree[i] - tree[i-1];
    }

    for(i = 0; i < n - 2; i++) {
        a = arr[i];
        b = arr[i+1];

        while(b != 0) {
            tmp = b;
            b = a % b;
            a = tmp;
        }
        if(a < min) min = a;
    }

    for(i = 1; i < n; i++) {
        if(tree[i] != tree[i-1] + min) {
            cnt++;
            tree[i-1] = tree[i-1] + min;
            i--;
        }
    }

    printf("%d",(arr[n-1]-arr[0])/min-n+1);
    

    return 0;
}