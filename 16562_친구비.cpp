#include<iostream>
#include<vector>
using namespace std;
int N, M, K;
vector<int> cost;
int main() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cost.push_back(x);
    }

    return 0;
}