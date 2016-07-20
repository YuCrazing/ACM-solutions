#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
int uN,vN;
int g[MAXN][MAXN], mp[MAXN][MAXN], a[MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u) {
    for(int v = 1; v <= vN; v++)
        if(g[u][v] && !used[v]) {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    return false;
}

int hungary() {
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 1; u <= uN; u++) {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}

void init(int n) {
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            g[i][j] = 0;
    uN = vN = n;
}

int main() {
    int n, m, u, v;
    while(scanf("%d%d", &n, &m) != EOF) {

        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                mp[i][j] = 0;

        for(int i = 1; i <= n; i ++) a[i] = i;
        for(int i = 0; i < m; i ++) {
            scanf("%d%d", &u, &v);
            mp[u][v] = 1;
        }

        int res = -1;
        if(n == 0) res = 0;
        else if(n == 1) {
            if(mp[1][1]) res = 1;
            else res = 0;
        } else {
            do {
                init(n);
                for(int i = 1; i <= n; i ++) {
                    for(int j = 1; j <= n; j ++) {
                        if(mp[i][a[j]] == 0 && mp[i][a[(j + n)%n + 1]] == 0) g[i][j] = 1;
                    }
                }
                res = max(res, hungary());
            } while(next_permutation(a + 2, a + 1 + n));
            res = n - res;
        }
        printf("%d\n", res);
    }
    return 0;
}
