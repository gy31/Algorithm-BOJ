#define M 1234567891
#include<stdio.h>
int L, num;
long long int r = 1, ans = 0;
char c[52];
int main() {
	scanf("%d %s", &L, &c);

	for(int i = 0; i < L; i++) {
        ans = (ans + (c[i]-'a'+1) * r) % M;
        r = (r * 31) % M;
	}
	printf("%lld", ans);

	return 0;
}