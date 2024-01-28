#include<stdio.h>
long long A, B, C;
long long func(long long a, long long b) {
    if(b == 0) return 1;
    if(b % 2 == 0) return func(a, b/2) * func(a, b/2) % C;
    else return (func(a, b/2) * func(a, b/2) % C) * a % C;
}
int main() {
    
    scanf("%lld%lld%lld", &A, &B, &C);

    printf("%lld", func(A, B));

    return 0;
}