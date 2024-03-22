#define MA 101
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> ans;
int N, arr[MA], visited[MA], flag;
void back(int a, int b) {
    if(visited[b]) return;
    if(a == b) {
        ans.push_back(a);
        return;
    }
    visited[b] = 1;
    back(a, arr[b]);
}
int main() {
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= N; i++) {
        fill(visited, visited+N+1, 0);
        back(i, arr[i]);
    }

    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}