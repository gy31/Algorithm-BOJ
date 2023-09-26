#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
pair<int ,int> t;
queue<pair<int,int>> q;
int N, M;
int map[8][8];
int zx[4]={1,-1,0,0},zy[4]={0,0,1,-1};
void BFS()
{
	int i,nx,ny,x,y;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		x=t.first; y=t.second;
		dab=map[x][y]-1;
		for(i=0;i<4;i++)
		{
			nx=x+zx[i]; ny=y+zy[i];
			if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
			if(map[nx][ny]) continue;
			cnt--;
			map[nx][ny]=map[x][y]+1;
			q.push(make_pair(nx,ny));
		}
	}
}
int main()
{
    int i, j, k, cnt = 0;
    scanf("%d%d", &N, &M);
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0) cnt++;
        }
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            for(k = 0; k < 3; k++) {
                
            }
        }
    }

    return 0;
}