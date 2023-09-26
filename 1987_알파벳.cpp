#include<stdio.h>
int r, c, max;
int chk[26];
char board[21][21];
void pro(int x, int y, int cnt) {
    int t = board[x][y] - 'A';
    if(max < cnt) max = cnt;
    if(chk[t] != 0) return;

    chk[t]++;
    if(x+1 < r) pro(x+1, y, cnt+1);
    if(x-1 >= 0) pro(x-1, y, cnt+1);
    if(y+1 < c) pro(x, y+1, cnt+1);
    if(y-1 >= 0) pro(x, y-1, cnt+1);
    chk[t]--;

}
int main()
{
    int i,j;
    scanf("%d%d", &r, &c);

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%c", &board[i][j]);
        }
    }

    pro(0, 0, 0);
    printf("%d", max);

    return 0;
}