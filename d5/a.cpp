#include <stdio.h>
#include <bitset>
#define MAX 100000

using namespace std;

bitset<100001> d[MAX+1], a1, a2;
int n, m;

int main()
{
    int i, x, s1, s2, e1, e2;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &x), d[i] = d[i-1], d[i].set(x);

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d %d", &s1, &e1, &s2, &e2);
        a1 = d[e1] & ~d[s1-1];
        a2 = d[e2] & ~d[s2-1];
        if(a1 == a2) printf("YES\n");
        else printf("NO\n");
    }
}