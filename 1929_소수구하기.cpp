#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    for(int i = M; i <= N; i++) {
        if(i > 1 && i <= 3) {
            cout << i << "\n";
        }
        int r = sqrt(i);
        for(int j = 2; j <= r; j++) {
            if(i % j == 0) {
                break;
            }
            if(j == r)
                cout << i << "\n";
        }
    }

    return 0;
}