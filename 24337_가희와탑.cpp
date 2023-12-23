#include<iostream>
using namespace std;
int ans[100001];

int main() {
    int N, a, b;
    cin >> N >> a >> b;

    for(int i = 0; i < N; i++) {
        ans[i] = 1;
    }

    if(a + b > N + 1) {
        cout << -1;
        return 0;
    }
    else if(a == 1) {
        ans[0] = b;
        for(int i = 1; i < N; i++) {
            ans[i] = ans[i-1] - 1 < 1 ? 1 : ans[i-1] - 1;
        }
    }
    else {
        ans[N-b] = max(a, b);
        for(int i = N-b+1; i < N; i++) {
            ans[i] = ans[i-1] - 1;
        }
        ans[N-b-1] = a - 1;
        for(int i = N-b-2; i > 0; i--) {
            ans[i] = ans[i+1] - 1;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}