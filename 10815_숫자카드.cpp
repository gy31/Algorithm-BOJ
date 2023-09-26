#include<stdio.h>
#include<algorithm>
using namespace std;
int snum[500000], fnum[500000];
int main()
{
    int i, n, m, num, low, high, mid;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &snum[i]);
    }

    sort(snum, snum+n);


    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        scanf("%d", &fnum[i]);
    }

    for(i = 0; i < m; i++){
        low = 0; high = n-1;
        num = fnum[i];

        while(1) {
            mid = (low+high) / 2;
            if(low > high) {
                printf("0 ");
                break;
            }
            if(num == snum[mid]) {
                printf("1 ");
                break;
            }
            else if(num > snum[mid]) {
                low = mid+1;
            }
            else if(num < snum[mid]) {
                high = mid-1;
            }
        }
    }


    return 0;
}