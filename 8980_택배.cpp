#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct deliver {
    int st;
    int ed;
    int box;
};
bool cmp(deliver i, deliver j) {
    return i.ed < j.ed;
}
int main() {
    int N, C, M, cnt = 0;
    cin >> N >> C >> M;
    vector<deliver> v(M, {0,0,0});

    for(int i = 0; i < M; i++) {
        cin >> v[i].st >> v[i].ed >> v[i].box;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < M; i++) {
        cout << v[i].st << v[i].ed << v[i].box;
        cout << "\n";
    }

    return 0;
}