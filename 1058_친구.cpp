#define INF 987654321
#define MA 51
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N, arr[MA][MA], ans;
int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) {
            if(s[j] == 'Y') arr[i][j] = arr[j][i] = 1;
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        int tmp = 0;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            if(arr[i][j] <= 2) tmp++;
        }
        ans = max(ans, tmp);
    }

    cout << ans;

    return 0;
}