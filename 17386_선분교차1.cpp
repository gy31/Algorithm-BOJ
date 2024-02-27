#include<stdio.h>
#include<algorithm>
using namespace std;
long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long a = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if(a > 0) return 1;
	else if(a == 0) return 0;
	else return -1;
}
int main() {
	int ans = 0;
	long long x1, x2, x3, x4, y1, y2, y3, y4, a, b, c, d;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	
	a = ccw(x1, y1, x2, y2, x3, y3);
	b = ccw(x1, y1, x2, y2, x4, y4);
	c = ccw(x3, y3, x4, y4, x1, y1);
	d = ccw(x3, y3, x4, y4, x2, y2);

	if(a*b <= 0 && c*d <= 0) ans = 1;
	if(a*b == 0 && c*d == 0) {
		if(min(x1, x2) <= max(x3, x4) && max(x1, x2) >= min(x3, x4) && min(y1, y2) <= max(y3, y4) && max(y1, y2) >= min(y3, y4)) ans = 1;
		else ans = 0;
	}
	
	printf("%d", ans);
	

	return 0;
}