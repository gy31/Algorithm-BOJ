#include<iostream>
using namespace std;
long long arrL[100001], arrR[100001];
long long answer;
int main() {
    int X, K;
    cin >> X >> K;

    for(int i = 0; i < X*2; i++) {
        int a;
        cin >> a;
        if(i < X) arrL[a] += 1;
        else arrR[a] += 1;
    }

    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= K; j++) {
            if(i == j) continue;
            answer += arrL[i] * arrR[j];
        }
    }

    cout << answer;

    return 0;
}