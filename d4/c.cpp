using namespace std;
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
 
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl
#define MOD 1000000007
 

vector<string> keywords;
string text;

const int MAXS = 2000001;
const int MAXC = 26;
 
int out[MAXS]; 
int f[MAXS];
int g[MAXS][MAXC];

int d[MAXS];
 
int bmm(const vector<string> &words, char lC = 'a',
        char hC = 'z')
{
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    int states = 1;
    for (int i = 0; i < words.size(); ++i)
    {
        const string &keyword = words[i];
        int cS = 0;
        for (int j = 0; j < keyword.size(); ++j)
        {
            int c = keyword[j] - lC;
            if (g[cS][c] == -1)
                g[cS][c] = states++;
            cS = g[cS][c];
        }
        out[cS] |= (1 << i);
    }
    for (int c = 0; c < MAXC; ++c)
    {
        if (g[0][c] == -1)
        {
            g[0][c] = 0;
        }
    }
 
    queue<int> q;
    for (int c = 0; c <= hC - lC; ++c){
        if (g[0][c] != -1 and g[0][c] != 0)
        {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size())
    {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= hC - lC; ++c)
        {
            if (g[state][c] != -1)
            {
                int failure = f[state];
                while (g[failure][c] == -1)
                {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure]; 
                q.push(g[state][c]);
            }
        }
    }
 
    return states;
}
int fns(int cS, char nextInput, char lC = 'a')
{
    int answer = cS;
    int c = nextInput - lC;
    while (g[answer][c] == -1)
        answer = f[answer];
    return g[answer][c];
}
 
int main()
{
	int n, i, len;

	cin >> n;
	for(i=1 ; i<=n ; i++)
	{
		string tmp;
		cin >> tmp;
		keywords.push_back(tmp);
	}
	cin >> text;
    len = text.size();

    bmm(keywords, 'A', 'Z');

    int cS = 0;
    for (int i = 0; i < len; ++i)
    {
        cS = fns(cS, text[i], 'A');
        if (out[cS] == 0)
            continue;
        for (int j = 0; j < keywords.size(); ++j)
        {
            if (out[cS] & (1 << j))
            { 
				if(i-keywords[j].size()+1 == 0)
                    d[i]++, d[i]%=MOD;
                else
                    d[i]+=d[i-keywords[j].size()], d[i]%=MOD;
            }
        }
    }
    printf("%d", d[len-1]);
    return 0;
}