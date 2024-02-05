#include<stdio.h>
#define M 1<<21
long long int T[M],a,b,c,dab;
int n, m, k,p;
void update(int x) {
	if(x<1) return;
	T[x]=T[x*2]+T[x*2+1];
	update(x/2);
}
void query(int x,int y) {
	while(1) {
		if(x%2==1) { dab+=T[x]; x++;}
		x/=2;
		if(y%2==0) { dab+=T[y]; y--;}
		y/=2;
		if(x==y) dab+=T[x];
		if(x>=y) break;
	}
}

int main() {
	int i;
	scanf("%d%d%d", &n,&m,&k);
	for(p=1;p<=n;p*=2);
	for (i = 0; i <n; i++) {
		scanf("%lld", &a);
		T[p+i]=a;
		update((p+i)/2);
	}
	for (i = 1; i <= m + k; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) {
			T[p+b-1]=c;
			update((p+b-1)/2);
		}
		else {
			dab=0;
			query(p+b-1, p+c-1);
			printf("%lld\n",dab);
		}
	}
	return 0;
}