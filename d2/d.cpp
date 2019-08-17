#include <stdio.h>
#include <vector>
using namespace std;

struct D{
    int sum;
    vector<int> check;
} d[16][16];

int a[16][16], n;
vector<int> tcheck;

int main()
{
    int i, j, k, l;
    int len, tsum, ok, idx, mx;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
        d[1][i].check.push_back(i);

    for(i=2 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
        {
            mx = 0;
            for(k=1 ; k<=n ; k++)
                if(k!=j)
                {
                    ok = 1;
                    tsum = d[i-1][k].sum;
                    len = d[i-1][k].check.size();
                    for(l=0 ; l<len ; l++)
                    {
                        if(d[i-1][k].check[l] == j) ok = 0;
                        else tsum+=a[j][d[i-1][k].check[l]];
                    }

                    if(ok == 1 && tsum>mx)
                        mx = tsum, tcheck = d[i-1][k].check, tcheck.push_back(j);
                }
            d[i][j].sum = mx;
            d[i][j].check = tcheck;
        }

    mx = 0;
    for(i=1 ; i<=n ; i++)
        mx = (d[n][i].sum>mx)?d[n][i].sum:mx;
    printf("%d", mx);
    return 0;
}