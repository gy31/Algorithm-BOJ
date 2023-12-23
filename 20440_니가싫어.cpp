#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
vector<pair<int, int>> v;
stack<pair<int, int>> s;
vector<int> cnt;
// int cnt[2100000001];
int main() {
    int N, ans1, ans2, max = 1, max_size = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        if(b > max_size) max_size = b;
    }

    cnt.resize(max_size+1, 0);
    sort(v.begin(), v.end());

    s.push(v[0]);
    cnt[v[0].first] = cnt[v[0].second] = 1;
    for(int i = 1; i < N; i++) {
        int in = v[i].first;
        int out = v[i].second;
        if(in >= s.top().second) {
            s.pop();
        }
        s.push(v[i]);
        cnt[in] = cnt[out] = s.size();
        if(s.size() > max) max = s.size();
    }

    for(int i = 1; i < max_size; i++) {
        if(cnt[i] == max) {
            ans1 = i;
            break;
        }
    }

    for(int i = max_size; i > 0; i--) {
        if(cnt[i] == max) {
            ans2 = i;
            break;
        }
    }

    cout << ans1 << " " << ans2 ;

    return 0;
}