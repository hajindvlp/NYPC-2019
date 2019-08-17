#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
 
const int MAXS = 200002; 
const int MAXC = 26;
const int MOD = 1000000007;
int d[MAXS];
int out[MAXS];
int f[MAXS]; 
int g[MAXS][MAXC];

vector<string> keywords;
string text;
queue<int> q;
 
int build(char lc, char hc)
{
	int c, i, j, cs, state;
	int states = 1, wlen, klen, failure; 

	for(i=0 ; i<MAXS ; i++) out[i] = 0;
	for(i=0 ; i<MAXS ; i++) f[i] = -1;
	for(i=0 ; i<MAXC ; i++)
		for(j=0 ; j<MAXC ; j++)
			g[i][j] = -1;

	wlen = keywords.size();
	for (i = 0; i < wlen; ++i)
	{
		cs = 0;
		klen = keywords[i].size();
		for (j = 0; j < klen; ++j)
		{
			c = keywords[i][j] - lc;
			if (g[cs][c] == -1)
				g[cs][c] = states++;
			cs = g[cs][c];
		}
		out[cs] |= (1 << i); 
	}

	for (c = 0; c < MAXC; ++c)
		if (g[0][c] == -1)
			g[0][c] = 0;

	for (c = 0; c <= hc - lc; ++c)
		if (g[0][c] != -1 and g[0][c] != 0)
		{
			f[g[0][c]] = 0;
			q.push(g[0][c]);
		}

	while (!q.empty())
	{
		state = q.front();
		q.pop();
		for (c = 0; c <= hc - lc; c++)
			if (g[state][c] != -1)
			{
				failure = f[state];
				while (g[failure][c] == -1)
					failure = f[failure];
				failure = g[failure][c];
				f[g[state][c]] = failure;
				out[g[state][c]] |= out[failure]; 
				q.push(g[state][c]);
			}
	}

	return states;
}
int findNextState(int cs, char nin, char lc)
{
    int ans = cs;
    int c = nin - lc;
    while (g[ans][c] == -1)
        ans = f[ans];
    return g[ans][c];
}
 
int main()
{
	int i, j;
	int n, len;
    int cs = 0;
    
	string tmp;

	cin >> n;
	for(i=0 ; i<n ; i++)
		cin >> tmp, keywords.push_back(tmp);

	cin >> text;
    build('A', 'Z');

	len = text.size();
    for (i = 0; i < len; i++)
    {
        cs = findNextState(cs, text[i], 'A');
        if (out[cs] == 0)
            continue;
        for (j = 0; j < n; j++)
            if (out[cs] & (1 << j))
            {
				if(i-keywords[j].size()+1 == 0) d[i]++, d[i]%=MOD;
				else d[i]+=d[i-keywords[j].size()], d[i]%=MOD;
            }
    }
	cout << d[len-1];
    return 0;
}