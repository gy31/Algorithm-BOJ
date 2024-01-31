#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, ans;
vector<int> p;
vector<int> z;
vector<int> m;
int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if(x > 0) p.push_back(x);
        else if(x == 0) z.push_back(x);
        else m.push_back(x);
    }

    sort(p.begin(), p.end());
    sort(m.begin(), m.end());

    for(int i = p.size() - 1; i >= 0; i--) {
        if(i == 0) {
            ans += p[i];
            break;
        }
        if(p[i] == 1 || p[i-1] == 1) {
            ans += p[i];
            continue;
        }
        ans += p[i] * p[i-1];
        i--;
    }

    for(int i = 0; i < m.size(); i++) {
        if(i == m.size() -1) {
            if(z.size() > 0 && m.size() % 2 == 1) {
                ans += 0;
            }
            else ans += m[i];
            break;
        }
        ans += m[i] * m[i+1];
        i++;
    }

    cout << ans;

    return 0;
}