#include<stdio.h>
#include<string.h>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;
/*
    stack is slow.
*/

const int N = 500 * 500 + 2;
const int CHARS = 26;

struct Node {
    int son[CHARS], next, cnt;
};

struct AC {
    Node node[N];
    int tol, top, n, pos[505], backtrack[N];
    char word[505];

    inline int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].cnt = 0;
        return tol++;
    }

    void init() {
        tol = top = 0;
        newNode();
    }

    void insert(char* s, int stringIndex) {
        int cur = 0;
        for(; *s; s++) {
            int& p = node[cur].son[*s - 'a'];
            if(!p) p = newNode();
            cur = p;
        }
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

                node[s].next = node[next].son[i];
                q.push(s);
                backtrack[top++] = s;
            }
        }
    }

    void search(char* s) {
        int cur = 0;
        for(; *s; s++) {
            cur = node[cur].son[*s - 'a'];
            node[cur].cnt++;
        }
        for(int i = top - 1; i >= 0; i--) {
            int cur = backtrack[i];
            int next = node[cur].next;
            node[next].cnt += node[cur].cnt;
        }
    }

    void read() {
        for(int i = 0; i < n; i++) {
            scanf("%s", word);
            insert(word, i);
        }
    }

    void print() {
        for(int i = 0; i < n; i++) {
            printf("%d\n", node[pos[i]].cnt);
        }
    }
} ac;


int T;
char text[N*4];
int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        ac.init();
        scanf("%d%s", &ac.n, text);
        ac.read();
        ac.bfs();
        ac.search(text);
        printf("Case %d:\n", ca);
        ac.print();
    }
    return 0;
}
