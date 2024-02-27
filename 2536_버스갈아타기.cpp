#include<stdio.h>
int M, N, K, sx, sy, ex, ey, ans = 5000;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int a = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if(a > 0) return 1;
    else if(a == 0) return 0;
    else return -1;
}
int main() {
    scanf("%d%d%d", &M, &N, &K);

    for(int i = 0; i < K; i++) {
        int b, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &b, &x1, &y1, &x2, &y2);
    }

    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    
    return 0;
}

/*
    x1 == x && y1 <= y <= y2
    y1 == y && x1 <= x <= x2
    이면 탈 수 있는 버스
*/