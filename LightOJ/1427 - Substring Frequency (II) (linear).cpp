#include<bits/stdc++.h>
using namespace std;

const int N = (500 * 500 + 3);
const int CHARS = 26;

struct Node {
    int son[CHARS], next, cnt;
    bool end;
};

struct AC {
    Node node[N];
    int tol, n, pos[505];
    stack<int> backtrack;

    int getid(char& x) {
        return x - 'a';
    }

    int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].cnt = node[tol].end = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(string& s, int stringIndex) {
        int cur = 0, l = s.size();
        for(int i = 0; i < l; i++) {
            int& p = node[cur].son[getid(s[i])];
            if(!p) p = newNode();
            cur = p;
        }
        node[cur].end = true;
        pos[stringIndex] = cur;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < CHARS; i++) if(node[0].son[i]) q.push(node[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            for(int i = 0; i < CHARS; i++) {

                int next = node[fa].next;
                int& s = node[fa].son[i];

                if(!s) {
                    s = node[next].son[i]; // so cool!!!
                    continue;
                }

                //while(next && !node[next].son[i]) next = node[next].next;

                node[s].next = node[next].son[i];
                q.push(s);
                backtrack.push(s);
            }
        }
    }

    void search(string& s) {
        int cur = 0, l = s.size();
        for(int i = 0; i < l; i++) {
            int id = getid(s[i]);
            cur = node[cur].son[id];
            node[cur].cnt++;
//            if(node[cur].end) node[cur].cnt++; // Wrong!
        }

        while(!backtrack.empty()) {
            int cur = backtrack.top();
            int next = node[cur].next;
            backtrack.pop();
            node[next].cnt += node[cur].cnt;
        }
    }

    void read() {
        string word;
        for(int i = 0; i < n; i++) {
            cin >> word;
            insert(word, i);
        }
    }

    void print() {
        for(int i = 0; i < n; i++) {
            printf("%d\n", node[pos[i]].cnt);
        }
    }

    void debug() {
        printf("tol = %d\n", tol);
        int cur = 0;
        for(int i = 0; i < tol; i++) printf("node[%d]->next = node[%d]\n", i, node[i].next);
    }

} ac;


int T;
string text;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        ac.init();
        cin >> ac.n >> text;
        ac.read();
        ac.bfs();
        //ac.debug();
        ac.search(text);
        printf("Case %d:\n", ca);
        ac.print();
    }
    return 0;
}

/*
100
7
abccab
a
ab
bab
bc
bca
c
caa
5
ababacbabc
aba
ba
ac
a
abc
3
lightoj
oj
light
lit
8
aaaaaaa
a
aa
aaa
aaaa
aaaaa
aaaaaa
aaaaaaa
aaaaaaaa
7
abcdef
abc
bcd
abcd
bcdef
defa
ab
a
*/
