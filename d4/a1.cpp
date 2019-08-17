#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, pair<int, int> > a[1001];
int n, mx;

int main()
{
    int i, j, x, y;
    int len;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) scanf("%d %d", &x, &y), a[i] = make_pair(x+y, make_pair(x, y));

    if(n<=20)
    {
        vector<int> d;  
        sort(a+1, a+n+1);
        d.push_back(0);

        for(i=1 ; i<=n ; i++)
        {
            len = d.size();
            for(j=0 ; j<len ; j++)
                if(d[j]<a[i].second.first)
                    d.push_back(d[j]+a[i].second.second), mx = (d[j]+a[i].second.second>mx)?d[j]+a[i].second.second:mx;
        }

        printf("%d", mx);
    }
    else
    {
        int d[200005], path[200005];
        for(i=0 ; i<=200000 ; i++) d[i] = 0, path[i] = 0;
        sort(a+1, a+n+1);
        d[0] = 1;
        for(i=1 ; i<=n ; i++)
            for(j=0 ; j<=200000 ; j++)
                if(d[j] && j<a[i].second.first && path[j]!=i)
                {                    
                    d[j+a[i].second.second] = 1;
                    mx = max(mx, j+a[i].second.second);
                    path[j+a[i].second.second] = (path[j+a[i].second.second] == 0)?i:path[j+a[i].second.second]; 
                }
        printf("%d", mx);
    }

    return 0;
}