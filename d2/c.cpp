#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

queue<int> Q;
int dy[4]={0, -1, 0, 1}, dx[4]={1, 0, -1, 0};
int a[401][401], d[401][401];
int n, m, k, sx, sy;

int main()
{
    int i, j;
    int yy, xx, ty, tx, cnt = 0;

    scanf("%d %d %d %d %d", &n, &m, &k, &sy, &sx);
    sy++;
    sx++;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]), a[i][j]+=k, a[i][j]%=4, d[i][j] = INF;

    Q.push(sy);
    Q.push(sx);
    d[sy][sx] = 0;
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        cnt = 0;
        for(i=a[yy][xx]+d[yy][xx] ; i<a[yy][xx]+d[yy][xx]+4 ; i++)
        {
            cnt++;
            ty = yy+dy[i%4];
            tx = xx+dx[i%4];
            if(ty>0 && ty<=n && tx>0 && tx<=m && d[ty][tx]>d[yy][xx]+cnt)
            {
                d[ty][tx] = d[yy][xx]+cnt;
                Q.push(ty);
                Q.push(tx);
            }
        }
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
            printf("%d ", d[i][j]+k);
        printf("\n");
    }
    return 0;
}