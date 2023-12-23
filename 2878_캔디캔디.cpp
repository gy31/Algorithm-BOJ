#include<iostream>
using namespace std;

int main() {
    int sum = 0;
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sum += a;
    }

    return 0;
}