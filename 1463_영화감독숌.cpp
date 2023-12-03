#include<iostream>
using namespace std;
int main() {
    int N, num = 665, cnt = 0;
    cin >> N;

    while(cnt != N) {
        num++;
        int tmp = num;
        while(tmp != 0) {
            if(tmp % 1000 == 666) {
                cnt++;
                break;
            }
            else {
                tmp /= 10;
            }
        }
    }

    cout << num;

    return 0;
}