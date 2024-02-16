#include<stdio.h>
int N, M;
long long tree[1<<21];
long long update(long long x, long long y, long long idx, long long a, long long b) {
    if(x > a || y < a) return tree[idx];
    if(x == y && x == a) return tree[idx] = b;
    long long mid = (x + y) / 2;
    return tree[idx] = update(x, mid, idx*2, a, b) + update(mid+1, y, idx*2+1, a, b);
}
long long query(long long x, long long y, long long idx, long long a, long long b) {
    if(x >= a && b >= y) return tree[idx];
    if(x > b || a > y) return 0;
    long long mid = (x + y) / 2;
    return query(x, mid, idx*2, a, b) + query(mid+1, y, idx*2+1, a, b);
}
int main() {
    scanf("%d%d", &N, &M);

    for(int i = 0; i < M; i++) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a == 0) {
            long long t = b < c ? query(1, N, 1, b, c) : query(1, N, 1, c, b);
            printf("%lld\n", t);
        }
        else if(a == 1) update(1, N, 1, b, c);
    }

    return 0;
}