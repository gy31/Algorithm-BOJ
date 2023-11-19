#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> v;
int N, K, answer, check;
void dfs(int alpCnt, int start, int check) {
    int cnt = 0;
    if(alpCnt == K) {
        for(int i = 0; i < v.size(); i++) {
            if((v[i] & check) == v[i]) cnt++;
        }
        if(answer < cnt) answer = cnt;
        return;
    }

    for(int i = start; i < 26; i++) {
        if((check & (1 << i)) == 0) {
            check |= (1 << i);
            dfs(alpCnt+1, i, check);
            check &= ~(1 << i);
        } 
    }
}
int main() {
    int bit = 0;
    cin >> N >> K;

    bit |= 1 << ('a' - 'a');
    bit |= 1 << ('n' - 'a');
    bit |= 1 << ('t' - 'a');
    bit |= 1 << ('i' - 'a');
    bit |= 1 << ('c' - 'a');

    check = bit;

    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        bit = check;
        for(int j = 4; j < word.length()-4; j++) {
            bit |= 1 << (word[j] - 'a');
        }
        v.push_back(bit);
    }

    if(K < 5) {
        cout << 0;
        return 0;
    } else if(K == 26) {
        cout << N;
        return 0;
    }

    dfs(5, 0, check);

    cout << answer;

    return 0;
}