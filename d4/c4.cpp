#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef unsigned char uchar;
const int K = 256;

class AhoCorasickTrie {
    struct node {
        unordered_map<uchar, node*> next;
        unordered_map<uchar, node*> jump;
        node *parent;
        uchar upchar;
        node *suff;
        node *uplink;
        bool terminal;
        short length;

        node(node *parent, uchar upchar) : 
            parent(parent),
            upchar(upchar),
            suff(0),
            uplink(0),
            terminal(false),
            length(0)
        { }
    };

    node *root;

    node *getSuff(node *v) {
        if (!v->suff) {
            if (v->parent == root) {
                v->suff = root;
            } else {
                v->suff = getJump(getSuff(v->parent), v->upchar);
            }
        }
        return v->suff;
    }

    node *getUplink(node *v) {
        if (!v->uplink) {
            node *u = getSuff(v);
            if (u == root) {
                v->uplink = root;
            } else if (u->terminal) {
                v->uplink = u;
            } else {
                v->uplink = getUplink(u);
            }
        }
        return v->uplink;
    }

    node *getJump(node *v, uchar c) {
        if (v->jump.find(c) == v->jump.end()) {
            if (v->next.find(c) != v->next.end()) {
                v->jump[c] = v->next[c];
            } else {
                v->jump[c] = v == root ? root : getJump(getSuff(v), c);
            }
        }
        return v->jump[c];
    }

public:
    AhoCorasickTrie() {
        root = new node(0, 0);
        root->parent = root;
    }

    void add(const string &sample) {
        node *v = root;
        for (uchar c : sample) {
            if (!v->next[c]) {
                v->next[c] = new node(v, c);
            }
            v = v->next[c];
        }
        v->terminal = true;
        v->length = sample.length();
    }

    vector<int> find(const string &text) {
        vector<int> r;
        node *v = root;
        for (int i = 0; i < (int)text.length(); ++i) {
            v = getJump(v, text[i]);
            for (node *u = v; u != root; u = getSuff(u)) {
                if (u->terminal) {
                    r.push_back(i - u->length + 1);
                }
            }
        }
        return r;
    }
};

int main()
{
    int n;
    cin >> n;
    AhoCorasickTrie dict;
    string ban, text;

    for(int i=0 ; i<n ; i++)
    {
        cin >> ban;
        dict.add(ban);
    }

    int m;
    cin >> text;
    vector<int> r;
    do{
        r = dict.find(text);
        
    }while(!r.empty());
}