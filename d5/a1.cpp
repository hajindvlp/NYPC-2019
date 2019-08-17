#include <stdio.h>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

set<int> t[400001], e;
int n, m, a[100001];

int gM(int x, int y)
{
    return x+(y-x)/2;
}

set<int> build(int ss, int se, int si)
{
    if(ss == se)  
    {
        t[si].insert(a[ss]);
        return t[si];
    }

    int m = gM(ss, se);
    set<int> s={}, fir, sec;
    fir = build(ss, m, si*2+1);
    sec = build(m+1, se, si*2+2);
    set_union(fir.begin(), fir.end(), sec.begin(), sec.end(), inserter(s, s.begin()));
    t[si] = s;
    return t[si];
}

set<int> query(int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)  
        return t[si];

    if (se < qs || ss > qe) 
        return e;

    int m = gM(ss, se);

    set<int> s={}, fir, sec;
    fir = query(ss, m, qs, qe, si*2+1);
    sec = query(m+1, se, qs, qe, si*2+2);
    set_union(fir.begin(), fir.end(), sec.begin(), sec.end(), inserter(s, s.begin()));
    return s;
}

int main()
{
    int i;
    int as, ae, bs, be;
    set<int> fir, sec;

    scanf("%d %d", &n, &m);
    for(i=0 ; i<n ; i++) scanf("%d", &a[i]);
    build(0, n-1, 0);

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d %d", &as, &ae, &bs, &be);
        fir = query(0, n-1, as-1, ae-1, 0);
        sec = query(0, n-1, bs-1, be-1, 0);
        if(fir == sec) printf("YES\n");
        else printf("N0\n");
    }
    return 0;
}