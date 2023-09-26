#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
int main() {
    int n, x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &x);
        if(x == 0) {
            if(pq.empty()) printf("0\n");
            else {
                printf("%d\n", pq.top().second);
                pq.pop();
            }
        }
        else {
            pq.push(make_pair(abs(x), x));
        }
    }

    return 0;
}