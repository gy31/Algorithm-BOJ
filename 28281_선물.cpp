#include<iostream>
#include<vector>
using namespace std;
vector<int> A;
int main() {
    int N, X, answer;
    cin >> N >> X;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(i == 0) A.push_back(a);
        else A.push_back(a + A[i-1]);
    }

    answer = A[1];
    for(int i = 2; i < N; i++) {
        if(A[i] - A[i-2] < answer) answer = A[i] - A[i-2];
    }

    cout << answer * X;

    return 0;
}