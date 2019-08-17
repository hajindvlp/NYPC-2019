#include <stdio.h>
#include <algorithm>
using namespace std;

int n, e;
int cnt;
pair<int, int> a[100001];

int main()
{
    int i, j, x, y;
    int mx, mn;

    scanf("%d %d", &n, &e);
    for(i=1 ; i<=n ; i++) scanf("%d %d", &x, &y), a[i] = make_pair(x, y);
    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
    {
        mx = mn = a[i].second;
        for(j=i ; j<=n ; j++)
        {
            mx = (a[j].second>mx)?a[j].second:mx;
            mn = (a[j].second<mn)?a[j].second:mn;
            if(mx-mn>2*e)
            {
                cnt++;
                break;
            }
        }
        i = j-1;
    }
    printf("%d", cnt+1);
    return 0;
}