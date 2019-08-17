#include <stdio.h>
#include <algorithm>
using namespace std;

int cnt[200001], parent[200001];
pair<int, int> wl[200001], mxwl;
int mx, n, m, idx, ans;

int find(int u)
{
    if (u == parent[u])
        return u;
 
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    if(u!=v) parent[find(v)] = parent[find(u)];
}

int main()
{
    int i, j, u;
    int x, y;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=n ; i++)
        parent[i] = i;
        
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d", &x, &y);
        wl[x].first++;
        wl[y].second--;
        merge(x, y);
    }

    for(i=1 ; i<=n ; i++)
    {
        u = find(i);
        parent[i] = u;
        cnt[u]++;
        if(cnt[u]>mx)
        {
            mx = cnt[u];
            idx = u;
        }
    }

    for(i=1 ; i<=n ; i++)
        if(parent[i] == idx && wl[i]>mxwl)
        {
            ans = i;
            mxwl = wl[i];
        }

    printf("%d", ans);
    return 0;
}