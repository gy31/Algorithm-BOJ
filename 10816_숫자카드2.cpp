#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v, f;
int main() {
    int N, M;
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
        f.push_back(a);
    }

    for(int i = 0; i < M; i++) {
        int a = upper_bound(v.begin(), v.end(), f[i]) - v.begin();
        int b = lower_bound(v.begin(), v.end(), f[i]) - v.begin();

        cout << a - b << " ";
    }

    return 0;
}