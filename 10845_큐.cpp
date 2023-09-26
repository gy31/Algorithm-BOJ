#include<stdio.h>
#include<string.h>
char a[6];
int queue[10000];
int main()
{
    int i, n, input=-1, output=-1;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s", a);
        if(strcmp(a, "push") == 0) {
            scanf("%d", &queue[++input]);
        }
        else if(strcmp(a, "pop") == 0) {
            if(input == output) printf("-1\n");
            else printf("%d\n", queue[++output]);
        }
        else if(strcmp(a, "size") == 0) printf("%d\n", input - output);
        else if(strcmp(a, "empty") == 0) {
            if(input == output) printf("1\n");
            else printf("0\n");
        }
        else if(strcmp(a, "front") == 0) {
            if(input == output) printf("-1\n");
            else printf("%d\n", queue[output+1]);
        }
        else if(strcmp(a, "back") == 0) {
            if(input == output) printf("-1\n");
            else printf("%d\n", queue[input]);
        }
    }

    return 0;
}