#include<stdio.h>
#include<math.h>
int a, b, c;
int chk[201][201][201], answer[201];
void dfs(int x, int y, int z) {
    if(chk[x][y][z] || x + y + z > c) return;
    chk[x][y][z] = 1;
    if(x == 0) answer[z] = 1;

    if(y+z > b) // z -> y
        dfs(x, b, abs(c-b-x));
    else 
        dfs(x, y+z, 0); 
    if(x+z > a) // z -> x
        dfs(a, y, abs(c-a-y));
    else 
        dfs(x+z, y, 0); 
    if(x+y > a) // y -> x
        dfs(a, abs(c-a-z), z);
    else
        dfs(x+y, 0, z); 
    if(x+y > b) // x -> y
        dfs(abs(c-b-z), b, z);
    else
        dfs(0, x+y, z); 
    // 전체 물 양은 c 보다 많을 수 없음
    dfs(x, 0, z+y); // y -> z
    dfs(0, y, x+z); // x -> z
}
int main() {

    scanf("%d%d%d", &a, &b, &c);

    dfs(0, 0, c);

    for(int i = 0; i <= c; i++) {
        if(answer[i]) printf("%d ", i);
    }

    return 0;
}