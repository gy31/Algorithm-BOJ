#include<stdio.h>
char ham[20001];
int main()
{
    int n, k, i, j, cnt = 0;
    scanf("%d%d", &n, &k);
    scanf("%s", ham);

    for(i = 0; i < n; i++) {
        if(ham[i] == 'P') {
            for(j = i - k; j <= i + k; j++) {
                if(j < 0 || j > n) continue;
                if(ham[j] == 'H') {
                    ham[j] = 0;
                    cnt++;
                    break;
                }
            }
        }
    }

    printf("%d", cnt);

    return 0;
}