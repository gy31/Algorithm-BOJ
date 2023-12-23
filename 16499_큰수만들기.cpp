#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> v;

bool cmp(string x, string y) {
    return x+y > y+x;
}

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), cmp);

    if(v[0] == "0") {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        
        cout << v[i];
    }

    return 0;
}
