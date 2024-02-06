#define MA 1 << 18
#include<stdio.h>
#include<algorithm>
using namespace std;
struct temp {
    int m, index;
} tree[MA];
int N, num[100001], ans;
struct temp make(int x, int y, int idx) {
    if(x == y) {
        tree[idx].m = num[x];
        tree[idx].index = x;
        return tree[idx];
    }
    int mid = (x + y) / 2;
    tree[idx] = (make(x, mid, idx*2).m < make(mid+1, y, idx*2+1).m) ? tree[idx*2] : tree[idx*2+1];
    return tree[idx];
}
struct temp query(int x, int y, int idx, int a, int b) {
    if(x >= a && y <= b) return tree[idx];
    if(x > b || y < a) return tree[0];

    struct temp v, w;
    int mid = (x + y) / 2;
    v = query(x, mid, idx*2, a, b);
    w = query(mid+1, y, idx*2+1, a, b);

    if(v.m < w.m) return v;
    else return w;
}
void divide(int x, int y) {
    if(x > y) return;
    struct temp t;
    t = query(1, N, 1, x, y);
    ans = max(ans, t.m * (y-x+1));
    divide(x, t.index-1);
    divide(t.index+1, y);
}

int main() {
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &num[i]);
    }

    make(1, N, 1);
    tree[0].m = 2000000000;
    divide(1, N);

    printf("%d", ans);

    return 0;
}