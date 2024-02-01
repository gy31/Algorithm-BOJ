#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, ans;
vector<int> arr;
int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++){
        int left, right;
        left = 0;
        right = N-1;
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(sum > arr[i]) right--;
            else if(sum < arr[i]) left++;
            else {
                if(i == left) left++;
                else if(i == right) right--;
                else {
                    ans += 1;
                    break;
                }
            }            
        }
    }

    cout << ans;

    return 0;
}