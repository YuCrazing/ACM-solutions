#include<bits/stdc++.h>
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 1e6 + 5;
int fa[N][21];
bool vis[N];
vector<int> g[N];

void dfs(int u, int f) {
    fa[u][0]=f;
    for(int i = 0; i < g[u].size(); ++i) {
        if(g[u][i]==f) continue;
        dfs(g[u][i], u);
    }
}

int main() {
    int n, k, u, v;
    scanf("%d%d", &n, &k);
    k = n-k;
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(n, n);
    for(int j = 1; j <= 20; ++j) {
        for(int i = 1; i <= n; ++i) {
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }

    --k;
    vis[n]=1;

    for(int i = n-1; i > 0; --i) {
        if(vis[i]) continue;

        int l=1, cur=i;
        for(int j = 20; j >= 0; --j) {
            if(!vis[fa[cur][j]]) {
                l += (1<<j);
                cur=fa[cur][j];
            }
        }

        if(l <= k) {
            k -= l;
            cur=i;
            do {
                vis[cur]=1;
                cur=fa[cur][0];
            } while(!vis[cur]);
        }

        if(!k) break;
    }
    for(int i = 1; i <= n; ++i) if(!vis[i]) printf("%d ", i);
    return 0;
}
