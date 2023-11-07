#include<iostream>
#include<string>
#include<vector>
vector<long long> v;
using namespace std;
int N, K, answer;
void dfs(int bit, int alp, int n) {
    int cnt = 0;
    if(n == K) {}

    for(int i = n; i < v.size(); i++) {
        dfs(bit | v[i], i+1);
    }
}
int main() {
    int bit = 0;
    cin >> N >> K;

    if(K < 5) {
        cout << 0;
        return 0;
    } else if(K == 26) {
        cout << N;
        return 0;
    }

    bit |= 1 << ('a' - 'a');
    bit |= 1 << ('n' - 'a');
    bit |= 1 << ('t' - 'a');
    bit |= 1 << ('i' - 'a');
    bit |= 1 << ('c' - 'a');

    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        for(int j = 4; j < word.length()-4; j++) {
            bit |= 1 << (word[j] - 'a');
        }
        v.push_back(bit);
    }
    dfs(0, 5, 0);

    cout << answer;

    return 0;
}