#include<stdio.h>
int s[30000], chk[3001];
int main()
{
    int i, n, d, k, c, max = 0, answer = 0;
    scanf("%d%d%d%d", &n, &d, &k, &c);

    for(i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    for(i = 0; i < n+k-1; i++) {
        if(chk[s[i%n]] == 0) max++;
        chk[s[i%n]]++;
        if(i >= k-1) {
            if(i>=k)              // 지나간 초밥이면 빼준다
			{
				chk[s[i-k]]--;
				if(chk[s[i-k]]==0) max--;
			}
            if(chk[c] == 0 && max+1 > answer) answer = max + 1;
            else if(max > answer) answer = max;
        }
    }

    printf("%d", answer);

    return 0;
}