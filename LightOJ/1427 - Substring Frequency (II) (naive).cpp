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
    int tol, n, pos[N];

    inline int getid(char& x) {
        return x - 'a';
    }

    void init() {
        for(int i = 0; i < N; i++) {
            memset(node[i].son, 0, sizeof(node[i].son));
            node[i].next = node[i].cnt = node[i].end = 0;
        }
        tol = 1;
    }

    void insert(string& s, int stringIndex) {
        int cur = 0, l = s.size();
        for(int i = 0; i < l; i++) {
            int& p = node[cur].son[getid(s[i])];
            if(!p) p = tol++;
            cur = p;
            if(i == l - 1) {
                //assert(node[cur].str == " "); //
                node[cur].end = true;
                pos[stringIndex] = cur;
            }
        }
    }

    void bfs() {
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            if(!fa) {
                for(int i = 0; i < CHARS; i++) {
                    int s = node[fa].son[i];
                    if(!s) continue;
                    q.push(s);
                }
            } else {
                for(int i = 0; i < CHARS; i++) {
                    int s = node[fa].son[i];
                    if(!s) continue;

                    int fanext = node[fa].next;
                    while(fanext && !node[fanext].son[i]) fanext = node[fanext].next;

                    if(node[fanext].son[i]) node[s].next = node[fanext].son[i];
                    q.push(s);
                }
            }
        }
    }

    void search(string& s) {
        int cur = 0, l = s.size();
        for(int i = 0; i < l; i++) {
            int id = getid(s[i]);
            while(cur && !node[cur].son[id]) {
                cur = node[cur].next;
            }
            if(node[cur].son[id]) cur = node[cur].son[id];

            int tmp = cur;
            while(tmp) { // important but slowly.
                if(node[tmp].end) node[tmp].cnt++;
                tmp = node[tmp].next;
            }
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
