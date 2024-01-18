#include<iostream>
#include<vector>
using namespace std;
int n, m;
int p[1001], chk[1001];
vector<int> enemy[1001];
int find(int x) {
    if(x == p[x]) return p[x];
    return p[x] = find(p[x]);
}
int main() {
    int ans = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for(int i = 1; i <= m; i++) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        if(a == 'F') {
            int x, y;
            x = find(b);
            y = find(c);
            if(x != y) p[y] = x;
        }
        else if(a == 'E') {
            enemy[b].push_back(c);
            enemy[c].push_back(b);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < enemy[i].size(); j++) {
            int x, y;
            x = find(enemy[i][j-1]);
            y = find(enemy[i][j]);
            if(x != y) p[y] = x;
        }
    }

    for(int i = 1; i <= n; i++) {
        int x = find(i);
        if(!chk[x]) {
            ans++;
            chk[x] = 1;
        }
    }

    cout << ans;
    
    return 0;
}