#define INF 100000000
#define MA 51
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, arr[MA][MA], cnt[MA], minCnt = INF, ans;
vector<int> ansArr;
int main() {
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    while(1) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a == -1 && b == -1) break;
        arr[a][b] = arr[b][a] = 1;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(arr[i][j] == 0 || arr[i][j] == INF) continue;
            cnt[i] = max(cnt[i], arr[i][j]);
        }
        if(cnt[i] < minCnt) minCnt = cnt[i];
    }

    for(int i = 1; i <= N; i++) {
        if(cnt[i] == minCnt) {
            ans++;
            ansArr.push_back(i);
        }
    }

    printf("%d %d\n", minCnt, ans);
    for(int i = 0; i < ansArr.size(); i++) {
        printf("%d ", ansArr[i]);
    }

    return 0;
}