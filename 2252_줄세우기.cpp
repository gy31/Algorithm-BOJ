#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> map;
int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }

    return 0;
}