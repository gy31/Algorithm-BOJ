#include<stdio.h>
char ball[500001];
int n, min = 500000;
int main()
{
    int i, r = 0, b = 0, cnt = 0;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%c", &ball[i]);
        if(ball[i] == 'R') r++;
        else b++;
    }

    // 빨간 공을 왼쪽으로 옮기는 경우
    for(i = 0; i < n; i++) {
        if(ball[i] == 'R') cnt++;
        else break;
    }
    if(min > r - cnt) min = r - cnt;
    cnt = 0;

    // 빨간 공을 오른쪽으로 옮기는 경우
    for(i = n-1; i >= 0; i--) {
        if(ball[i] == 'R') cnt++;
        else break;
    }
    if(min > r - cnt) min = r - cnt;
    cnt = 0;

    // 파란 공을 왼쪽으로 옮기는 경우
    for(i = 0; i < n; i++) {
        if(ball[i] == 'B') cnt++;
        else break;
    }
    if(min > b - cnt) min = b - cnt;
    cnt = 0;

    // 파란 공을 오른쪽으로 옮기는 경우
    for(i = n-1; i >= 0; i--) {
        if(ball[i] == 'B') cnt++;
        else break;
    }
    if(min > b - cnt) min = b - cnt;

    printf("%d", min);

    return 0;
}