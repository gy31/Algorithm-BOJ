#include<stdio.h>
int main() {
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N*2-1; i++) {
        if(i <= N) {
            for(int j = 0; j < N-i; j++) {
                printf(" ");
            }
            for(int j = 0; j < 2*i-1; j++) {
                printf("*");
            }
        }
        else {
            for(int j = 0; j < i-N; j++) {
                printf(" ");
            }
            for(int j = N*2-1; j > (i-N)*2; j--) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}