#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main() {
    int K, N;
    long long st = 1, ed = 0, mid, cm = 0;
    cin >> K >> N;

    for(int 
    i = 0; i < K; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        if(a > ed) ed = a;
    }

    while(st <= ed) {
        long long sum = 0;
        mid = (st + ed) / 2;
        for(int i = 0; i < K; i++) {
            sum += v[i] / mid;
        }
        if(sum >= N) {
            if(cm < mid) cm = mid;
            st = mid + 1;
        }
        else if(sum < N) ed = mid - 1;
    }

    cout << cm;

    return 0;
}