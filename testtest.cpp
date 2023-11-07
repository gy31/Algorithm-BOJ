#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int h1, m1, s1, h2, m2, s2;
    int cnt = 0;

    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    int start, end, time;
    int h, m, s;
    
    h = h1; m = m1; s = s1;
    start = h1 * 3600 + m1 * 60 + s1;
    end = h2 * 3600 + m2 * 60 + s2;
    time = end - start;
    
    for(int i = 1; i <= time; i++) {
        if(s == m || s == h) cnt += 1;
        s += 1;
        if(s == 60) {
            s = 0; m += 1;
        }
        if(m == 60) {
            m = 0; h += 1;
        }
    }
    
    cout << cnt;
    return cnt;
}