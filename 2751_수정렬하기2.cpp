#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}