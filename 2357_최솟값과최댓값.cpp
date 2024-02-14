#define MA 1000100
#define INF 1000000001
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, minTree[MA], maxTree[MA], num[MA];
void make(int x, int y, int idx) {
    if(x == y) {
        minTree[idx] = maxTree[idx] = num[x];
        return;
    }
    int mid = (x + y) / 2;
    make(x, mid, idx*2);
    make(mid + 1, y, idx*2+1);

    minTree[idx] = min(minTree[idx*2], minTree[idx*2+1]);
    maxTree[idx] = max(maxTree[idx*2], maxTree[idx*2+1]);
    return;
}
int query_min(int x, int y, int idx, int a, int b) {
    if(a <= x && y <= b) return minTree[idx];
    if(a > y || b < x) return INF;
    
    int mid = (x + y) / 2;
    return min(query_min(x, mid, idx*2, a, b), query_min(mid+1, y, idx*2+1, a, b));
}
int query_max(int x, int y, int idx, int a, int b) {
    if(a <= x && y <= b) return maxTree[idx];
    if(a > y || b < x) return 0;
    
    int mid = (x + y) / 2;
    return max(query_max(x, mid, idx*2, a, b), query_max(mid+1, y, idx*2+1, a, b));
}
int main() {
    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &num[i]);
    }

    make(1, N, 1);

    for(int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d %d\n", query_min(1, N, 1, a, b), query_max(1, N, 1, a, b));
    }

    return 0;
}