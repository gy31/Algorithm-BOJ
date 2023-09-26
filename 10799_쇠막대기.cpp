#include<stdio.h>
#include<string.h>
char stack[100001];
char t[100001];
int main()
{
    int i, cnt = 0, key = -1;

    scanf("%s", t);

    for(i = 0; i < strlen(t); i++) {
        if(key == -1 || t[i] == '(') {
            stack[++key] = t[i];
        }
        else if(t[i] == ')') {
            key--;
            if(t[i-1] == ')') cnt += 1;
            else if(key > -1) cnt += key+1;
        }
    }
    
    printf("%d", cnt);

    return 0;
}