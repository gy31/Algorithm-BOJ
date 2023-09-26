#include<stdio.h>
#include<string.h>
int stack[100001];
int main()
{
    int n, i, key = -1;
    char input[6];
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s", input);
        if(strcmp(input, "push") == 0) {
            scanf("%d", &stack[++key]);
        }
        else if(strcmp(input, "pop") == 0) {
            if(key == -1) printf("-1\n");
            else printf("%d\n", stack[key--]);
        }
        else if(strcmp(input, "size") == 0) {
            printf("%d\n", key+1);
        }
        else if(strcmp(input, "empty") == 0) {
            if(key == -1) printf("1\n");
            else printf("0\n");
        }
        else if(strcmp(input, "top") == 0) {
            if(key == -1) printf("-1\n");
            else printf("%d\n", stack[key]);
        }
    }

    return 0;
}