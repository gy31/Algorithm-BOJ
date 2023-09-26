#include<stdio.h>
#include<queue>
using namespace std;
priority_queue <int, vector<int>, less<int>> pq;
int main() {
    int n, x, st; // x가 자연수면 배열에 x 추가, 0이면 최소값 출력 후 제거

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &x);
        if(x == 0) {
            if(pq.size() == 0) {
                printf("0\n");
            }
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else { // 자연수가 입력되면
            pq.push(x);
        }
    }

    return 0;
}