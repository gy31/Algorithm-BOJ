#include<stdio.h>
int N, Q;
long long tree[1<<21], num[100001];
long long make(long long x, long long y, long long idx) {
    if(x == y) return tree[idx] = num[x];
    long long mid = (x + y) / 2;
    return tree[idx] = make(x, mid, idx*2) + make(mid+1, y, idx*2+1);
}
long long update(long long x, long long y, long long idx, long long a, long long b) {
    if(x > a || y < a) return tree[idx];
    if(x == y && x == a) return tree[idx] = b;
    long long mid = (x + y) / 2;
    return tree[idx] = update(x, mid, idx*2, a, b) + update(mid+1, y, idx*2+1, a, b);
}
long long query(long long x, long long y, long long idx, long long a, long long b) {
    if(a <= x && y <= b) return tree[idx];
    if(x > b || y < a) return 0;
    long long mid = (x + y) / 2;
    return query(x, mid, idx*2, a, b) + query(mid+1, y, idx*2+1, a, b);
}
int main() {
    scanf("%d%d", &N, &Q);

    for(int i = 1; i <= N; i++) {
        scanf("%lld", &num[i]);
    }

    make(1, N, 1);

    for(int i = 1; i <= Q; i++) {
        long long x, y, a, b;
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        long long t = x < y ? query(1, N, 1, x, y) : query(1, N, 1, y, x);
        printf("%lld\n", t);
        update(1, N, 1, a, b);
    }

    return 0;
}