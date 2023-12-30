#include<iostream>
using namespace std;

int main() {
    int N, M, ans = 0;
    cin >> N >> M;

    if(N == 1 || M == 1) ans = 1;
    else if(N == 2) ans = min(4, (M+1)/2);
    else if(M < 7) ans = min(4, M);
    else ans = M-2;

    cout << ans;
    
    return 0;
}