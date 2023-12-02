#include<iostream>
#include<vector>
#include<string>
using namespace std;
char map[1001][1001];
int cnt[3][1001][1001];
int M, N, K, a, b, c, d;
int main() {

    cin >> M >> N >> K;
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    for(int i = 1; i <= M; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= N; j++) {
            map[i][j] = tmp[j-1];
        }
    }

    for(int i = 1; i <= M; i++) {
        if(map[i][1] == 'J') cnt[0][i][1] = 1;
        else if(map[i][1] == 'O') cnt[1][i][1] = 1;
        else if(map[i][1] == 'I') cnt[2][i][1] = 1;
        cnt[0][i][1] += cnt[0][i-1][1];
        cnt[1][i][1] += cnt[1][i-1][1];
        cnt[2][i][1] += cnt[2][i-1][1];
    }

    for(int i = 1; i <= N; i++) {
        if(map[1][i] == 'J') cnt[0][1][i] = 1;
        else if(map[1][i] == 'O') cnt[1][1][i] = 1;
        else if(map[1][i] == 'I') cnt[2][1][i] = 1;
        cnt[0][1][i] += cnt[0][1][i-1];
        cnt[1][1][i] += cnt[1][1][i-1];
        cnt[2][1][i] += cnt[2][1][i-1];
    }

    for(int i = 2; i <= M; i++) {
        for(int j = 2; j <= N; j++) {
            cnt[0][i][j] = cnt[0][i][j-1] + cnt[0][i-1][j] - cnt[0][i-1][j-1];
            cnt[1][i][j] = cnt[1][i][j-1] + cnt[1][i-1][j] - cnt[1][i-1][j-1];
            cnt[2][i][j] = cnt[2][i][j-1] + cnt[2][i-1][j] - cnt[2][i-1][j-1];
            if(map[i][j] == 'J') cnt[0][i][j] += 1;
            else if(map[i][j] == 'O') cnt[1][i][j] += 1;
            else if(map[i][j] == 'I') cnt[2][i][j] += 1;
        }
    }

    for(int i = 0; i < K; i++) {
        cin >> a >> b >> c >> d;
        int J = cnt[0][c][d] - cnt[0][c][b-1] - cnt[0][a-1][d] + cnt[0][a-1][b-1];
        int O = cnt[1][c][d] - cnt[1][c][b-1] - cnt[1][a-1][d] + cnt[1][a-1][b-1];
        int I = cnt[2][c][d] - cnt[2][c][b-1] - cnt[2][a-1][d] + cnt[2][a-1][b-1];
        cout << J << " " << O << " " << I << "\n";
    }

    return 0;
}