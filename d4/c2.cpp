using namespace std; 
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>

const int MAXS = 200000; 
const int MAXC = 26; 
const int MOD = 1000000007;
int out[MAXS], d[MAXS];   
int f[MAXS]; 
int g[MAXS][MAXC]; 
string arr[MAXS];
string text; 
int n;
vector<pair<int, int> > p;

int bM(int k) 
{ 
    memset(out, 0, sizeof out); 
  
    memset(g, -1, sizeof g); 
  
    int states = 1; 
  
    for (int i = 0; i < k; ++i) 
    { 
        const string &word = arr[i]; 
        int cs = 0;
        int len = word.size(); 
  
        for (int j = 0; j < len; ++j) 
        { 
            int ch = word[j] - 'A'; 
  
            if (g[cs][ch] == -1) 
                g[cs][ch] = states++; 
  
            cs = g[cs][ch]; 
        } 
  
        out[cs] |= (1 << i); 
    } 
  
    for (int ch = 0; ch < MAXC; ++ch) 
        if (g[0][ch] == -1) 
            g[0][ch] = 0; 
  
    memset(f, -1, sizeof f); 
    queue<int> q; 
  
    for (int ch = 0; ch < MAXC; ++ch) 
    { 
        if (g[0][ch] != 0) 
        { 
            f[g[0][ch]] = 0; 
            q.push(g[0][ch]); 
        } 
    } 
  
    while (q.size()) 
    { 
        int state = q.front(); 
        q.pop(); 
  
        for (int ch = 0; ch <= MAXC; ++ch) 
        { 
            if (g[state][ch] != -1) 
            { 
                int failure = f[state]; 
  
                while (g[failure][ch] == -1) 
                      failure = f[failure]; 
  
                failure = g[failure][ch]; 
                f[g[state][ch]] = failure; 
  
                out[g[state][ch]] |= out[failure]; 
                q.push(g[state][ch]); 
            } 
        } 
    } 
  
    return states; 
} 
  
int fN(int cs, char nextInput) 
{ 
    int answer = cs; 
    int ch = nextInput - 'A'; 
  
    while (g[answer][ch] == -1) 
        answer = f[answer]; 
  
    return g[answer][ch]; 
} 
  
void sW(int k) 
{ 
    bM(k); 
    int cs = 0, i, j; 

    for (i = 0; i < n; ++i) 
    { 
        cs = fN(cs, text[i]); 
  
        if (out[cs] == 0) 
             continue; 
        for (j = 0; j < k; ++j) 
            if (out[cs] & (1 << j)) 
                p.push_back(make_pair(i-arr[j].size()+1, i));
    } 

    sort(p.begin(), p.end());
    int len = p.size();
    for(i=0 ; i<len ; i++)
    {
        if(p[i].first == 0) d[p[i].second]++;
        else d[p[i].second]+=d[p[i].first-1];
        d[p[i].second]%=MOD; 
    }
} 

int main() 
{ 
    int k, i;

    scanf("%d", &k);
    for(i=0 ; i<k ; i++)
        cin >> arr[i];
    cin >> text;
    n = text.size();
    sW(k); 
    printf("%d", d[n-1]);
    return 0; 
}