#include<iostream>
#include<vector>
#include<queue>
using namespace std;
string map[8];
int next[9][2] = {{0,0}, {-1,0}, {-1,1}, {-1,-1}, {0,1},{0,-1}, {1,0},{1,1},{1,-1}};
int main() {
    for(int i = 0; i < 8; i++) {
        cin >> map[i];
    }

    return 0;
}