#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> v;
map<int, int> chk;
int main() {
    int N, ans = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        chk[a] = 1;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                int sum = v[i] + v[j] + v[k];
                if(chk[sum] == 1 && sum > ans) ans = sum; 
            }
        }
    }

    cout << ans;

    return 0;
}