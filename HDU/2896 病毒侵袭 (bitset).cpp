#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>
#include<bitset>
#include<algorithm>
using namespace std;

typedef bitset<17> _int;

const int N = 1e5 + 5;
const int CHARS = 9;

struct Node {
    _int son[CHARS], next, virus[3];
    int cnt;
};

struct AC {
    Node node[N];
    int tol, ans;

    int newNode() {
        for(int i = 0; i < CHARS; i++) node[tol].son[i].reset();
        node[tol].next.reset();
        node[tol].cnt = 0;
        //assert(tol < N);
        return tol++;
    }

    void init() {
        tol = ans = 0;
        newNode();
    }

    void insert(char* s, int index) {
        _int cur(0);
        for(; *s; s++) {
            _int& son = node[cur.to_ulong()].son[*s - 32];
            if(!son.any()) son = _int(newNode());
            cur = son;
        }
        node[cur.to_ulong()].virus[node[cur.to_ulong()].cnt++] = _int(index);
    }

    void bfs() {
        queue<_int> q;
        for(int i = 0; i < CHARS; i++) if(node[0].son[i].any()) q.push(node[0].son[i]);
        while(!q.empty()) {
            _int fa = q.front();
            q.pop();
            for(int i = 0; i < CHARS; i++) {

                _int& son = node[fa.to_ulong()].son[i];
                _int next = node[fa.to_ulong()].next;

                if(!son.any()) {
                    son = node[next.to_ulong()].son[i];
                    continue;
                }

                node[son.to_ulong()].next = node[next.to_ulong()].son[i];
                q.push(son);

                // add virus
                int& n = node[next.to_ulong()].cnt;
                int& m = node[fa.to_ulong()].cnt;

                int id = 0;
                while(m < 3 && id < n) {
                    node[fa.to_ulong()].virus[m++] = node[next.to_ulong()].virus[id];
                    id++;
                }
            }
        }
    }

    void search(char* s, int index) {
        _int cur(0);
        int cnt = 0, res[3];
        for(; *s; s++) {
            cur = node[cur.to_ulong()].son[*s - 32];
            int& n = node[cur.to_ulong()].cnt;
            int& m = cnt;

            int id = 0;
            while(m < 3 && id < n) {
                res[m++] = (int)node[cur.to_ulong()].virus[id].to_ulong();
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

    void debug(){
        printf("---\n");
        for(int i = 0; i < tol; i++){
            printf("node[%d]: next = %d, cnt = %d\n", i, node[i].next.to_ulong(), node[i].cnt);
            for(int j = 0; j < node[i].cnt; j++) printf("  virus[%d] = %d\n", i, node[i].virus[j].to_ulong());
        }
        printf("---\n");
    }

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
