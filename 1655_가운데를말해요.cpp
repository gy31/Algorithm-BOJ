#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
    int i, n, x;
    int n1, n2, s1, s2;
    priority_queue<int, vector<int>, less<int>> pq1; // 최대힙
    priority_queue<int, vector<int>, greater<int>> pq2; // 최소힙

    // 최대힙과 최소힙의 사이즈를 같게 유지
    // 항상 pq1.top()이 출력

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        if(i == 0) {
            pq1.push(x);
            printf("%d\n", pq1.top());
            continue;
        }
        else if(pq2.size() == 0) {
            if(pq1.top() <= x) pq2.push(x);
            else {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(x);
            }
            printf("%d\n", pq1.top());
            continue;
        }
        n1 = pq1.top(); n2 = pq2.top();
        s1 = pq1.size(); s2 = pq2.size();

        if(n1 <= x && x <= n2) {
            if(s1 == s2) pq1.push(x);
            else if(s1 > s2) pq2.push(x);
        }
        else if(x < n1) {
            if(s1 == s2) pq1.push(x);
            else if(s1 > s2) {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(x);
            }
        }
        else if(x > n2) {
            if(s1 == s2) {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(x);
            }
            else if(s1 > s2) pq2.push(x);
        }
        printf("%d\n", pq1.top());
    }

    return 0;
}