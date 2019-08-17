#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;

pair<int, int> p[402];
ull a[401][401];
ull d[401];
ull INF = 100000000000;
int visit[401], path[401];
int rn, bn;

int abs(int x)
{
    if(x<0) return -x;
    return x;
}

int main()
{
    int i, j, v;
    int x, y;
    ull sum = 0, mn;

    scanf("%d %d", &rn, &bn);

    for(i=1 ; i<=rn+bn ; i++)
    {
        d[i] = INF;
        for(j=1 ; j<=rn+bn ; j++)
            a[i][j] = INF;
    }
    for(i=1 ; i<=rn ; i++)
        scanf("%d %d", &x, &y), p[i] = make_pair(x, y);
    for(i=1 ; i<=bn ; i++)
    {
        scanf("%d %d", &x, &y), p[i+rn] = make_pair(x, y);
        for(j=1 ; j<=rn ; j++)
            a[i+rn][j] = a[j][i+rn] = abs(p[i+rn].first-p[j].first)+abs(p[i+rn].second-p[j].second);
    }

    if(rn == 0 || bn == 0)
    {
        printf("-1");
        return 0;
    }

    d[1] = 0;

    for(i=1 ; i<=rn+bn ; i++)
    {
        mn = INF;
        v = -1;
        for(j=1 ; j<=rn+bn ; j++)
            if(visit[j] == 0 && d[j]<mn)
                mn = d[j], v = j;
                
        if(v == -1)
        {
            printf("-1");
            return 0;
        }
        
        visit[v] = 1;
        sum+=mn;

        for(j=1 ; j<=rn+bn ; j++)
            if(d[j]>a[v][j] && !visit[j])
                d[j] = a[v][j], path[j] = v;
    }

    printf("%llu", sum);
    return 0;
}