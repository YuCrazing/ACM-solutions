#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 200003;
const int INF = 0x3f3f3f3f;
vector<int> g[MAXN];

struct Node {
    int c, d, id;
    Node (int _c = 0, int _d = INF):c(_c), d(_d) {};
    bool operator<(const Node& b)const {
        return d > b.d;
    }
} a[MAXN];

int in[MAXN], ans[MAXN];
bool vis[MAXN];
priority_queue<Node> Q;

int dfs(int u) {

    if(vis[u]) return a[u].d;
    vis[u] = 1;

    int sz = g[u].size();
    int res = a[u].d;
    for(int i = 0; i < sz; i ++) {
        int v = g[u][i];
        res = min(res, dfs(v));
    }

    return a[u].d = res;
}


int main() {
    int n, u, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &a[i].d, &a[i].c, &k);
        a[i].id = i;
        while(k --) {
            scanf("%d", &u);
            g[u].push_back(i);
            in[i] ++;
        }
    }

    for(int i = 1; i <= n; i ++)if(in[i] == 0) dfs(i);

    bool ok = 1;
    int t = 0, ct = 0;
    for(int i = 1; i <= n; i ++) if(in[i] == 0) Q.push(a[i]);
    while(!Q.empty()) {
        Node u = Q.top();
        Q.pop();
        t += u.c;
        if(t > u.d) {
            ok = 0;
            break;
        }
        ans[++ ct] = u.id;
        int sz = g[u.id].size();
        for(int i = 0; i < sz; i ++) {
            int v = g[u.id][i];
            in[v] --;
            if(in[v] == 0) Q.push(a[v]);
        }
    }
    if(ct != n) ok = 0;
    if(ok) {
        printf("YES\n");
        for(int i = 1; i <= n; i ++) printf((i == n) ? "%d\n" : "%d ", ans[i]);
    } else printf("NO\n");

    return 0;
}
