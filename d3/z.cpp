#include <stdio.h>
#include <algorithm>
using namespace std;

pair<pair<int, int>, int> p[22][22];
int a[22][22], d[22][22], s[22][22];

int n, m, c1, c2;

int main()
{
    int i, j;
    char tmp[10005];
    int ok;
    int nx, ny, x, y;

    scanf("%d %d %d %d", &n, &m, &c1, &c2);

    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=m ; j++)
            if(tmp[j] == 'X')
                a[i][j] = 1;
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            s[i][j] = a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
        {
            ok = 0;
            if(a[i][j] == 0 && i>=2 && j>=2 && s[i][j]-s[i-2][j]-s[i][j-2]+s[i-2][j-2] == 0 && d[i][j]<d[i-2][j]+d[i][j-2]-d[i-2][j-2]+c1)
                d[i][j] = d[i-2][j]+d[i][j-2]-d[i-2][j-2]+c1, p[i][j] = make_pair(make_pair(i-2, j-2), 1), ok = 1;
            if(a[i][j] == 0 && i>=3 && j>=1 && s[i][j]-s[i-3][j]-s[i][j-1]+s[i-3][j-1] == 0 && d[i][j]<d[i-3][j]+d[i][j-1]-d[i-3][j-1]+c2)
                d[i][j] = d[i-3][j]+d[i][j-1]-d[i-3][j-1]+c2, p[i][j] = make_pair(make_pair(i-3, j-1), 2), ok = 1;
            if(d[i][j]<d[i-1][j])
                d[i][j] = d[i-1][j];
            if(d[i][j]<d[i][j-1])
                d[i][j] = d[i][j-1];
        }            

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
            printf("%05d : %d | ", d[i][j], p[i][j].second);
        printf("\n");
    }
}