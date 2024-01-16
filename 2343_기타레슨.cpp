#include<iostream>
using namespace std;
int arr[100001];
int main() {
    int N, M, st = 1, ed = 1000000000, mid, ans = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(arr[i] > st) st = arr[i];
    }

    while(st <= ed) {
        int sum = 0, cnt = 1;
        mid = (st+ed) / 2;

        for(int i = 0; i < N; i++) {
            if(sum + arr[i] > mid) {
                sum = arr[i];
                cnt++;
            }
            else sum += arr[i];
        }
        if(cnt <= M) ans = mid;
        if(cnt > M) st = mid + 1;
        else ed = mid - 1;
    }

    cout << ans;

    return 0;
}