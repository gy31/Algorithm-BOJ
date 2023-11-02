#include<vector>
#include<string>
#include<iostream>
using namespace std;
vector<long long> v;
int alp = (1 << 26) - 1;
int cnt;
void dfs(int bit, int n) {
    if(bit == alp) cnt++;

    for(int i = n; i < v.size(); i++) {
        dfs(bit | v[i], i+1);
    }
}
int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        int bit = 0;
        for(int j = 0; j < word.length(); j++) {
            bit |= 1 << (word[j] - 'a');
        }
        v.push_back(bit);
    }

    dfs(0, 0);

    cout << cnt;

    return 0;
}