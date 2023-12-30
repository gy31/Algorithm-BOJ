#include<iostream>
using namespace std;
int arr[10000001] = {1, 1};
long long int ans;
void chk(int a) {
    long long int tmp = 0;
    while(a > 0) {
        tmp = tmp * 10 + a % 10;
        a /= 10;
    }
    ans = tmp;
}
int main() {
    int N;
    cin >> N;

    for(int i = 2; i*i <= 10000000; i++) {
        for(int j = i+i; j <= 10000000; j+=i) {
            arr[j] = 1;
        }
    }

    for(int i = N; i <= 10000000; i++) {
        if(!arr[i]) chk(i);
        if(ans == i) {
            cout << ans;
            return 0;
        }
    }

    return 0;
}