#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main() {
    int N, M;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cin >> M;
    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;

        cout << binary_search(v.begin(), v.end(), a) << "\n";
    }

    return 0;
}