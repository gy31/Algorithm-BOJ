#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> v;
stack<int> s;
int arr[1000001], ans[1000000];

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        arr[a] += 1;
    }

    for(int i = N - 1; i >= 0; i--) {
        int num = v[i];
        if(s.size() == 0) {
            ans[i] = -1;
            s.push(num);
        }
        else {
            int t = s.top();
            if(arr[num] < arr[t]) {
                ans[i] = t;
                s.push(num);
            }
            else {
                s.pop();
                i++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}