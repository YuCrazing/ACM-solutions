#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>
#include<bitset>
#include<algorithm>
using namespace std;

/*
    Why 24MB memory be used?
*/

const int N = 1e5 + 5;
const int CHARS = 96;

struct Node {
    int son[CHARS], next, virus[3], cnt;
};

struct AC {
    Node node[N];
    int tol, ans;

    int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].cnt = 0;
        //assert(tol < N);
        return tol++;
    }

    void init() {
        tol = ans = 0;
        newNode();
    }

    void insert(char* s, int index) {
        int cur = 0;
        for(; *s; s++) {
            int& son = node[cur].son[*s - 32];
            if(!son) son = newNode();
            cur = son;
        }
        node[cur].virus[node[cur].cnt++] = index;
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

                // add virus
                int& n = node[next].cnt;
                int& m = node[fa].cnt;

                int id = 0;
                while(m < 3 && id < n) {
                    node[fa].virus[m++] = node[next].virus[id];
                    id++;
                }
            }
        }
    }

    void search(char* s, int index) {
        int cur = 0, cnt = 0, res[3];
        for(; *s; s++) {
            cur = node[cur].son[*s - 32];
            int& n = node[cur].cnt;
            int& m = cnt;

            int id = 0;
            while(m < 3 && id < n) {
                res[m++] = (int)node[cur].virus[id];
                id++;
            }
            if(m >= 3) break;
        }

        if(cnt > 0) {
            ans++;
            sort(res, res + cnt);
            printf("web %d: ", index);
            for(int i = 0; i < cnt; i++) printf((i == cnt - 1) ? "%d\n" : "%d ", res[i]);
        }
    }

//    void debug(){
//        printf("---\n");
//        for(int i = 0; i < tol; i++){
//            printf("node[%d]: next = %d, cnt = %d\n", i, node[i].next.to_ulong(), node[i].cnt);
//            for(int j = 0; j < node[i].cnt; j++) printf("  virus[%d] = %d\n", i, node[i].virus[j].to_ulong());
//        }
//        printf("---\n");
//    }

} ac;


char word[222], text[10010];
int main() {
    int n, m;
    while(scanf("%d", &n) != EOF) {
        ac.init();
        for(int i = 0; i < n; i++) {
            scanf("%s", word);
            ac.insert(word, i + 1);
        }
        ac.bfs();
        //ac.debug();
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%s", text);
            ac.search(text, i + 1);
        }
        printf("total: %d\n", ac.ans);
    }
    return 0;
}
