#include<bits/stdc++.h>
using namespace std;

const int N = 500 * 500 + 5;
const int chars = 26;

struct Node {
    int son[chars], cnt, next;
};

struct AC {
    Node node[N];
    int n, tol, pos[505];
    stack<int> st;
    char text[N * 4];

    int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].cnt = node[tol].next = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char *s, int id) {
        int cur = 0;
        for(; *s; s++) {
            int& son = node[cur].son[*s - 'a'];
            if(!son) son = newNode();
            cur = son;
        }
        pos[id] = cur;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < chars; i++) if(node[0].son[i]) q.push(node[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            for(int i = 0; i < chars; i++) {
                int& son = node[fa].son[i];
                int next = node[fa].next;
                if(!son) {
                    son = node[next].son[i];
                    continue;
                }
                q.push(son);
                st.push(son);
                node[son].next = node[next].son[i];
            }
        }
    }

    void search(char* s) {
        int cur = 0;
        for(; *s; s++) {
            cur = node[cur].son[*s - 'a'];
            node[cur].cnt++;
        }
        while(!st.empty()) {
            int cur = st.top();
            st.pop();
            int next = node[cur].next;
            node[next].cnt += node[cur].cnt;
        }
    }

    void read() {
        char word[505];
        scanf("%d%s", &n, text);
        for(int i = 0; i < n; i ++) {
            scanf("%s", word);
            insert(word, i);
        }
    }

    void print(int ca) {
        printf("Case %d:\n", ca);
        for(int i = 0; i < n; i++)
            printf("%d\n", node[pos[i]].cnt);
    }

    void debug() {
        printf("---\n");
        for(int i = 0; i < tol; i++)
            printf("node[%d].cnt = %d, next = %d\n", i, node[i].cnt, node[i].next);
        printf("---\n");
    }

    void gao(int ca) {
        init();
        read();
        bfs();
        search(text);
        //debug();
        print(ca);
    }

} ac;

int main() {
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        ac.gao(ca);
    }
    return 0;
}
