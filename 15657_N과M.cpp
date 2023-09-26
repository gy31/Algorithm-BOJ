#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m;
int num[8], dab[8];
void pro(int k, int p) {
    if(k == m) {
        for(int i = 0; i < k; i++) {
            printf("%d ", dab[i]);
        }
        printf("\n");
        return;
    }

    for(int i = p; i < n; i++) {
        dab[k] = num[i];
        pro(k+1, i);
    }
}
int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    sort(num, num+n);

    pro(0, 0);
   
    return 0;
}