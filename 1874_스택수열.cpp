#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
vector <char> answer;
int stack[100001], num[100001], chk[100001];
int main()
{
    int i, n, key = -1, cnt = 1, stop = 0;
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }

    i = 1;
    while(cnt <= n) {
        if(key == -1 || stack[key] < num[cnt]) {
            answer.push_back('+');
            stack[++key] = i++;
        }
        else {
            if(stack[key] == num[cnt]) {
                cnt++;
                chk[stack[key]]++;
            }
            answer.push_back('-');
            if(chk[stack[key]] == 0) {
                printf("NO");
                exit(0);
            }
            key--;
        }
    }

    for(i = 0; i < answer.size(); i++) {
        printf("%c\n", answer[i]);
    }

    return 0;
}