#include<stdio.h>
int score[6][3];
void pro(int x, int y) {
    if(y == 6) {x++; y = x+1;}
    if(x == 5 && y == 6) {
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 6; j++) {
                sum += score[i][j];
            }
        }
        if(sum == 0) printf("%d ", 1);
        else printf("%d ", 0);
        return;
    }
    
    if(score[x][0] > 0 && score[y][2] > 0) {score[x][0]--; score[y][2]--;}
    if(score[x][1] > 0 && score[y][1] > 0) {score[x][1]--; score[y][1]--;}
    if(score[x][2] > 0 && score[y][0] > 0) {score[x][2]--; score[y][0]--;}
    pro(x, y+1);
}
int main()
{
    int i, j, k;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 6; j++) {
            for(k = 0; k < 3; k++) {
                scanf("%d", &score[j][k]);
            }
        }
        pro(0,1);
    }

    return 0;
}