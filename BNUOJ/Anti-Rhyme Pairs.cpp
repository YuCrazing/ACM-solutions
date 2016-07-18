#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXM = 1e6 + 2;
const int MAXN = 1e5 + 2;
const int DEG = 20;

struct Trie {
    int ch[26], deg, fa[DEG];
} node[MAXM];


int pos[MAXN], cnt;
int insert(char s[]) {
    int l = strlen(s), u = 0;
    for(int i = 0; i < l; i ++) {
        if(node[u].ch[s[i] - 'a']) u = node[u].ch[s[i] - 'a'];
        else {
            node[u].ch[s[i] - 'a'] = ++cnt;
            node[cnt].fa[0] = u;
            node[cnt].deg = node[u].deg + 1;
            u = cnt;
            for(int i = 1; i < DEG; i ++) node[u].fa[i] = node[node[u].fa[i - 1]].fa[i - 1];
        }
    }
    return u;
}

int LCA(int u, int v) {
    if(u == v) return u;
    if(node[u].deg > node[v].deg) swap(u, v);
    int hu = node[u].deg;
    int hv = node[v].deg;
    int tu = u;
    int tv = v;
    for(int i = 0, det = hv - hu; det; det >>= 1, i ++)
        if(det & 1) tv = node[tv].fa[i];
    if(tu == tv) return tu;
    for(int i = DEG - 1; i > -1; i --) {
        if(node[tu].fa[i] == node[tv].fa[i]) continue;
        tu = node[tu].fa[i];
        tv = node[tv].fa[i];
    }
    return node[tu].fa[0];
}
char s[MAXN];
int main() {
    int T, n, m, u, v;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        memset(node, 0, sizeof(node));
        cnt = 0;
        node[0].fa[0] = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) {
            scanf("%s", s);
            pos[i] = insert(s);
        }
        printf("Case %d:\n", cas);
        scanf("%d", &m);
        for(int i = 0; i < m; i ++) {
            scanf("%d%d", &u, &v);
            u --;
            v --;
            printf("%d\n", node[LCA(pos[u], pos[v])].deg);
        }
    }
    return 0;
}
