#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string arr[65][65];
string func(int x, int y, int size) {
    string ans;
    if(size == 1) return arr[x][y];
    for(int i = x; i < x+size; i++) {
        for(int j = y; j < y+size; j++) {
            if(arr[x][y] != arr[i][j]) {
                ans += "(";
                ans += func(x, y, size/2);
                ans += func(x, y+size/2, size/2);
                ans += func(x+size/2, y, size/2);
                ans += func(x+size/2, y+size/2, size/2);
                ans += ")";
                return ans;
            }
        }
    }
    return arr[x][y];
}
int main() {
    int N;
    string s;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s;
        for(int j = 0; j < N; j++) {
            arr[i][j] = s[j];
        }
    }

    cout << func(0, 0, N);

    return 0;
}