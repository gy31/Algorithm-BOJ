#include<iostream>
using namespace std;
int arr[101], multitap[101], chk[101], now[101];
int main() {
    int N, K, answer = 0, idx = 1, idx2 = 0;
    int maxN = 0;
    cin >> N >> K;

    for(int i = 1; i <= K; i++) {
        cin >> arr[i];
        chk[arr[i]] += 1;
        if(arr[i] > maxN) maxN = arr[i];
    }

    for(int i = 1; i <= K; i++) {
        if(idx > N) {
            idx2 = i;
            break;
        }
        if(!now[arr[i]]) {
            multitap[idx] = arr[i];
            now[arr[i]] = 1;
            idx++;
        }
        chk[arr[i]] -= 1;
    }

    if(idx < N) {
        cout << 0;
        return 0;
    }

    for(int i = idx2; i <= K; i++) {
        int min = 100, next = 0;
        if(now[arr[i]]) {
            chk[arr[i]] -= 1;
            continue;
        }
        for(int j = 1; j <= maxN; j++) {
            if(chk[j] < min) {
                min = chk[j];
                next = j;
            }
        }
        for(int j = 1; j <= N; j++) {
            if(multitap[j] == next) {
                now[multitap[j]] = 0;
                multitap[j] = arr[i];
                now[arr[i]] = 1;
                break;
            }
        }
        chk[arr[i]] -= 1;
        answer++;
    }

    cout << answer;

    return 0;
}