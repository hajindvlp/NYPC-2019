#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> a[1001];
int d[200001], n, mx, p[200001];

int main()
{
    int i, j;
    int x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &x, &y), a[i] = make_pair(x, y);
    sort(a+1, a+n+1);

    d[0] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=0 ; j<=200000 ; j++)
            if(d[j] && a[i].first>j)
                d[j+a[i].second] = 1, mx = (j+a[i].second>mx)?j+a[i].second:mx;
    printf("%d\n", mx);
}