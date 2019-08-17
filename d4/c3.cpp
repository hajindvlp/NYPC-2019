#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

string a[100001], target;
vector<pair<int, int> > p;
int d[200001];
int n;

int main()
{
    int i, j;
    size_t t;

    cin >> n;
    for(i=1 ; i<=n ; i++) cin >> a[i];
    cin >> target;
    for(i=1 ; i<=n ; i++)
    {   
        t = -1;
        while(1)
        {
            t = target.find(a[i], t+1);
            if(t == string::npos)
                break;
            else
                p.push_back(make_pair(t, a[i].size()));
        }
    }

    sort(p.begin(), p.end());
    int len = p.size();
    for(i=0 ; i<len ; i++)
    {
        if(p[i].first == 0) d[p[i].first+p[i].second-1]++;
        else d[p[i].first+p[i].second-1]+=d[p[i].first-1];
        d[p[i].first+p[i].second-1]%=MOD;
    }

    cout << d[target.size()-1];
}