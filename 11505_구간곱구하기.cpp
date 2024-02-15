#define MOD 1000000007
#include<stdio.h>
int N, M, K, num[1000001];
long long tree[1<<21];
long long make(long long x, long long y, long long idx) {
    if(x == y) {
        tree[idx] = num[x];
        return tree[idx];
    }
    long long mid = (x + y) / 2;
    return tree[idx] = make(x, mid, idx*2) * make(mid+1, y, idx*2+1) % MOD;
}
long long update(long long x, long long y, long long idx, long long a, long long b) {
    if(x > a || y < a) return tree[idx];
    if(x == y && x == a) {
        tree[idx] = b;
        return tree[idx];
    }
    long long mid = (x + y) / 2;
    return tree[idx] = update(x, mid, idx*2, a, b) * update(mid+1, y, idx*2+1, a, b) % MOD;
}
long long query(long long x, long long y, long long idx, long long a, long long b) {
    if(x > b || y < a) return 1;
    if( a <= x && b >= y) return tree[idx];
    long long mid = (x + y) / 2;
    return query(x, mid, idx*2, a, b) * query(mid+1, y, idx*2+1, a, b) % MOD;
}
int main() {
    scanf("%d%d%d", &N, &M, &K);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &num[i]);
    }

    make(1, N, 1);

    for(int i = 1; i <= M+K; i++) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a == 1) update(1, N, 1, b, c);
        else if(a == 2) printf("%lld\n", query(1, N, 1, b, c)%1000000007);
    }

    return 0;
}