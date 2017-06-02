/*
* HDU 2222 Keywords Search
* 求文本串 text 中出现了几个单词串 word.
* Aho-Corasick算法: 要求掌握 KMP 算法和 Tire.
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5; // Length's sum of all words.
const int L = 1e6 + 6; // Length of text.
const int CHARS = 26; // Numbers of characters.

stack<int> st;

struct Node {
    int son[CHARS], next, end;
    bool vis;
};

struct AC {

    Node node[N];
    int tol;

    int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].end = node[tol].vis = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char *s) {
        int l = strlen(s), cur = 0;
        for(int i = 0; i < l; i++) {
            int& son = node[cur].son[s[i] - 'a'];
            if(!son) son = newNode();
            cur = son;
        }
        node[cur].end++; //
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < CHARS; i++) if(node[0].son[i]) q.push(node[0].son[i]);

        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int nex = node[fa].next;
            for(int i = 0; i < CHARS; i++) {
                int& son = node[fa].son[i];
                if(!son) {
                    son = node[nex].son[i];
                } else {
                    node[son].next = node[nex].son[i];
                    q.push(son);
                    st.push(son);
                }
            }
        }

    }

    int search(char *s) {
        int l = strlen(s), cur = 0;
        for(int i = 0; i < l; i++) {
            cur = node[cur].son[s[i] - 'a'];
            node[cur].vis = true;
        }

        int ans = 0;
        while(!st.empty()) {
            int cur = st.top();
            if(node[cur].vis) {
                node[node[cur].next].vis = true;
            }
            st.pop();
        }

        for(int i = 0; i < tol; i++) if(node[i].vis) ans += node[i].end;

        return ans;
    }
} ac;

int n, T;
char word[55], text[L];
int main() {
    scanf("%d", &T);
    while(T--) {

        ac.init();

        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", word);
            ac.insert(word);
        }

        ac.bfs();

        scanf("%s", text);
        printf("%d\n", ac.search(text));
    }
    return 0;
}
