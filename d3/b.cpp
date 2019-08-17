#include <bits/stdc++.h> 
#include <math.h> 
using namespace std; 
  
int st[262150], a[100000];
int n, mxs, m;

int getm(int s, int e) {  
    return s + (e - s)/2;  
} 
  
int queryrec(int ss, int se, int qs, int qe, int si) 
{ 
    if (qs <= ss && qe >= se) 
        return st[si]; 
  
    if (se < qs || ss > qe) 
        return 0; 
  
    int md = getm(ss, se); 
    return queryrec(ss, md, qs, qe, 2*si+1) ^ 
        queryrec(md+1, se, qs, qe, 2*si+2); 
} 

void updaterec(int ss, int se, int i, int prev_val, int new_val, int si) 
{ 
    if (i < ss || i > se) 
        return; 
  
    st[si] = (st[si]^prev_val)^new_val; 
    if (se != ss) 
    { 
        int md = getm(ss, se); 
        updaterec(ss, md, i, prev_val, new_val, 2*si + 1); 
        updaterec(md+1, se, i, prev_val, new_val, 2*si + 2); 
    } 
} 
  
void update(int i, int new_val) 
{ 
    if (i < 0 || i > n-1) 
    { 
        printf("Invalid Input"); 
        return; 
    } 
    int temp = a[i]; 
    a[i] = new_val; 
   
    updaterec(0, n-1, i, temp, new_val, 0); 
} 
  
int query(int qs, int qe) 
{ 
    return queryrec(0, n-1, qs, qe, 0); 
} 
  
int buildrec(int ss, int se, int si) 
{ 
    if (ss == se) 
    { 
        st[si] = a[ss]; 
        return a[ss]; 
    } 
    int md = getm(ss, se); 
    st[si] = buildrec(ss, md, si*2+1) ^ buildrec(md+1, se, si*2+2); 
    return st[si]; 
} 

void build() 
{ 
    buildrec(0, n-1, 0); 
} 
  
int main() 
{ 
    int i, j;
    int t, x, y;
    
    scanf("%d %d", &n, &m);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);

    build();

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1)
            update(x-1, y);
        else
            printf("%d\n", query(x-1, y-1));
    }
    return 0; 
} 
