#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct rect {
	double x1, y1, x2, y2;
};
int N;
vector<rect> v;
vector<double> x;
vector<double> y;
int main() {
	double ans = 0;
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		double a, b, c, d;
		rect t;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		t.x1 = a, t.y1 = b; t.x2 = a+c; t.y2 = b+d;
		x.push_back(a); x.push_back(a+c);
		y.push_back(b); y.push_back(b+d);
		v.push_back(t);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for(int i = 1; i < x.size(); i++) {
        if(x[i-1] == x[i]) continue;
        for(int j = 1; j < y.size(); j++) {
            if(y[j-1] == y[j]) continue;
            for(int k = 0; k < v.size(); k++) {
                if(v[k].x1 <= x[i-1] && v[k].x2 >= x[i] && v[k].y1 <= y[j-1] && v[k].y2 >= y[j]) {
                    ans += (x[i] - x[i-1]) * (y[j] - y[j-1]);
                    break;
                }
            }
        }
    }

    if((long long) ans == ans) printf("%lld", (long long) ans);
    else printf("%.2lf", ans);

	return 0;
}