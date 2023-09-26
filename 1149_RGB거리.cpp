#define MIN(x,y) (((x)<(y)) ? (x):(y))
#include<stdio.h>
#include<algorithm>
using namespace std;
int rgb[1000][3];
int main()
{
    int i, n;
    scanf("%d", &n);
    scanf("%d%d%d", &rgb[0][0], &rgb[0][1], &rgb[0][2]);

    for(i = 1; i < n; i++) {
        scanf("%d%d%d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
        rgb[i][0] = MIN(rgb[i][0] + rgb[i-1][1], rgb[i][0] + rgb[i-1][2]);
        rgb[i][1] = MIN(rgb[i][1] + rgb[i-1][0], rgb[i][1] + rgb[i-1][2]);
        rgb[i][2] = MIN(rgb[i][2] + rgb[i-1][0], rgb[i][2] + rgb[i-1][1]);
    }

    printf("%d", MIN(MIN(rgb[n-1][0], rgb[n-1][1]), rgb[n-1][2]));

    return 0;
}