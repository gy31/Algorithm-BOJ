#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> arr;
int main() {
    string s, t = "";
    char c;
    bool flag = true;
    int minus = 0, ans = 0;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        c = s[i];
        if(c >= '0' && c <= '9') {
            t += c;
        }
        if(c == '+' || i == s.size()-1) {
            if(flag) arr.push_back(stoi(t));
            else minus += stoi(t);
            t = "";
        }
        else if(c == '-') {
            if(arr.size() == 0 || flag) arr.push_back(stoi(t));
            else minus += stoi(t);
            flag = false;
            t = "";
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        ans += arr[i];
    }

    cout << ans - minus;

    return 0;
}