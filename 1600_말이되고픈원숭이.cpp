#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int K, W, H;
int map[200][200];
int nx[8] = {-2,-1,1,2,-2,-1,1,2}, ny[8] = {-1,-2,-2,-1,1,2,2,1};
int main() {
    cin >> K >> W >> H;
    for(int i = 0; i < H; i++) {
       for(int j = 0; j < W; j++) {
            cin >> map[i][j];
       } 
    }

    return 0;
}