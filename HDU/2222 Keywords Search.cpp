#include<bits/stdc++.h>
using namespace std;

/*
    Caution: same words.
*/

const int N = 50 * 10000 + 5;
const int CHARS = 26;

struct Node {
    int son[CHARS], next, cnt, end;
};

struct AC {
    Node node[N];
    stack<int> st;
    int tol, ans;

    int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].cnt = node[tol].end = 0;
        return tol++;
    }

    void init() {
        tol = ans = 0;
        newNode();
    }

    void insert(char* s) {
        int cur = 0;
        for(; *s; s++) {
            int& son = node[cur].son[*s - 'a'];
            if(!son) son = newNode();
            cur = son;
        }
        node[cur].end++;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < CHARS; i++) if(node[0].son[i]) q.push(node[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            for(int i = 0; i < CHARS; i++) {
                int& son = node[fa].son[i];
                int next = node[fa].next;
                if(!son) {
                    son = node[next].son[i];
                    continue;
                }
                node[son].next = node[next].son[i];
                q.push(son);
                st.push(son);
            }
        }
    }

    void search(char* s) {

        int cur = 0;
        for(; *s; s++) {
            assert((*s - 'a') >= 0);
            cur = node[cur].son[*s - 'a'];
            node[cur].cnt = 1;
        }
//        debug();
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            int next = node[cur].next;
            node[next].cnt = node[next].cnt | node[cur].cnt;
        }
        for(int i = 0; i < tol; i++) if(node[i].cnt) ans += node[i].end;
        printf("%d\n", ans);
    }

    void debug() {
        for(int i = 0; i < tol; i++)
            printf("node[%d]: next = %d, end = %d, cnt = %d\n", i, node[i].next, node[i].end, node[i].cnt);
    }
} ac;

char word[55], text[1000010];

int main() {
    int T,n;
    while(scanf("%d", &T) != EOF) {
        for(int ca = 1; ca <= T; ca++) {
            scanf("%d", &n);
            ac.init();
            for(int i = 0; i < n; i++) {
                scanf("%s", word);
                ac.insert(word);
            }
            ac.bfs();
            scanf("%s", text);
            ac.search(text);
        }
    }
    return 0;
}
/*
100

5
she
he
say
shr
her
yasherhs

2
aa
aa
aaaaaa

*/
