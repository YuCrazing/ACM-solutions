#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
vector<int> g[MAXN];
bool vis[MAXN];
int ct, node[MAXN], f[MAXN];
int rt = -1, rtcc = -1;
void dfs1(int u, int fa) {
    vis[u] = 1;
    int sz = g[u].size();
    for(int i = 0; i < sz; i ++) {
        int v = g[u][i];
        if(vis[v]) {
            if(v == fa) {
                if(f[u] == fa && f[fa] == u) {
                    node[ct] = v;
                }

            } else {
                node[ct] = v;
            }
        }
        if(u == v) {
            rt = v;
            rtcc = ct;
        }
        if(!vis[v] && v != fa) dfs1(v, u);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n;  i++) {
        scanf("%d",&f[i]);
        g[f[i]].push_back(i);
        g[i].push_back(f[i]);
    }
    ct = 0;
    for(int i = 1; i <= n;  i++)
        if(!vis[i]) {
            ct ++;
            dfs1(i, 0);
        }

    int ans;
    if(rt == -1) {
        ans = ct;
        for(int i = 1; i <= ct; i ++) f[node[i]] = node[1];
    } else {
        ans = ct - 1;
        for(int i = 1; i <= ct; i ++) if(i != rtcc) f[node[i]] = rt;
    }

    printf("%d\n", ans);
    for(int i = 1; i <= n; i ++) printf((i == n) ? "%d\n" : "%d ", f[i]);

    return 0;
}
/*
5
2 1 5 3 4
*/
