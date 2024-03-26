#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
stack<char> ST;
vector<char> ans;
int main() {
    int cnt = 0;
    string s, bomb;
    cin >> s >> bomb;

    for(int i = 0; i < s.size(); i++) {
        ST.push(s[i]);
        if(ST.top() == bomb[bomb.size()-1] && ST.size() >= bomb.size()) {
            string tmp = "";
            for(int j = bomb.size()-1; j >= 0; j--) {
                if(ST.top() != bomb[j]) {
                    for(int k = tmp.size()-1; k >= 0; k--) {
                        ST.push(tmp[k]);
                    }
                    break;
                }
                if(!ST.empty()) { tmp += ST.top(); ST.pop(); }
            }
        }
    }

    if(ST.empty()) {
        printf("FRULA");
        return 0;
    }

    while(!ST.empty()) {
        ans.push_back(ST.top());
        ST.pop();
    }

    for(int i = ans.size() - 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }

    return 0;
}