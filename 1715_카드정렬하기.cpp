#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    int i, n, x, cnt=0;
    int a, b;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }

    while(pq.size() > 1) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a+b);
        cnt += a+b;
    }

    printf("%d", cnt);

    return 0;
}