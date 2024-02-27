#include<stdio.h>
#include<algorithm>
using namespace std;
int x1, y1, x2, y2, x3, y3, x4, y4;
long long ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long a = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if(a > 0) return 1;
    else if(a == 0) return 0;
    else return -1;
}
int main() {
    long long a, b, c, d;
    int ans = 0;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    a = ccw(x1, y1, x2, y2, x3, y3);
    b = ccw(x1, y1, x2, y2, x4, y4);
    c = ccw(x3, y3, x4, y4, x1, y1);
    d = ccw(x3, y3, x4, y4, x2, y2);

    if(a*b < 0 && c*d < 0) ans = 1;

    printf("%d", ans);

    return 0;
}