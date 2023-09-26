#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
pair <int, int> t;
queue <pair<int, int>> q;
int M, N;
int map[1000][1000], tomato[1000][1000];
int zx[4]={1,-1,0,0},zy[4]={1,-1,-1,1};
void bfs(int a, int b) {
    int i,nx,ny,x,y;
	while(!q.empty())
	{
		t = q.front();
		q.pop();
		x = t.first; y = t.second;
		map[x][y];
		for(i = 0; i < 4; i++)
		{
			nx = x + zx[i]; ny = y + zy[i];
			if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if(map[nx][ny] == -1) continue;
			tomato[nx][ny] = tomato[x][y]+1;
			q.push(make_pair(nx,ny));
		}
	}
}
int main()
{
    int i, j;
    scanf("%d%d", &M, &N);

    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            if(map[i][j]) {
                q.push(make_pair(i, j));
                tomato[i][j] = 1;
            }
        }
    }

    return 0;
}