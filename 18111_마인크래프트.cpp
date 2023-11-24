#include<iostream>
using namespace std;
int map[501][501];
int main() {
    int N, M, B, minTime = 987654321, height = 0, time = 0;
    cin >> N >> M >> B;

    int tmp = B;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i <= 256; i++) {
        B = tmp; time = 0;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(map[j][k] > i) {
                    time += 2 * (map[j][k] - i);
                    B += map[j][k] - i;
                }
                else if(map[j][k] < i) {
                    time += i - map[j][k];
                    B -= i - map[j][k];
                }
            }
        }
        if(time >= 0 && B >= 0 && time <= minTime) {
            minTime = time;
            height = i;
        }
    }

    cout << minTime << " " << height;

    return 0;
}