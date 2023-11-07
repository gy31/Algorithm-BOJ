#include<stdio.h>
int N;
char tree[26][2];
void first(char n) {
    if(n == '.') return;
    printf("%c", n);
    first(tree[n - 'A'][0]);
    first(tree[n - 'A'][1]);
}
void mid(char n) {
    if(n == '.') return;
    mid(tree[n - 'A'][0]);
    printf("%c", n);
    mid(tree[n - 'A'][1]);
}
void last(char n) {
    if(n == '.') return;
    last(tree[n - 'A'][0]);
    last(tree[n - 'A'][1]);
    printf("%c", n);
}
int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char a, b, c;
        scanf(" %c %c %c", &a, &b, &c);
        tree[a-'A'][0] = b;
        tree[a-'A'][1] = c;
    }

    first('A');
    printf("\n");
    mid('A');
    printf("\n");
    last('A');
    printf("\n");

    return 0;
}