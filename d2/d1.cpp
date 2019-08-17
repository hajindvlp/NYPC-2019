#include <stdio.h>

int a[16][16];
int list[16], check[16];
int n;
int mx;

void out()
{
    int i, j;
    int sum = 0;


    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<i ; j++)
            sum+=a[list[i]][list[j]];

    if(sum>mx) mx = sum;
}

void rec(int lev)
{
    int i;
    
    if(lev == n+1)
    {
        out();
        return;
    }
    else
        for(i=1 ; i<=n ; i++)
            if(check[i] == 0)
            {
                list[lev] = i, check[i] = 1;
                rec(lev+1);
                check[i] = 0;
            }
}

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    rec(1);
    printf("%d", mx);
    return 0;
}