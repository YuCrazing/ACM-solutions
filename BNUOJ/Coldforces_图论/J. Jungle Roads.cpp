#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

vector<pair<int, int> > g[30];

int dis[30], vis[30];
void prim(int s, int n) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for(int i = 0; i < n; i ++) {
        int minn = INF, u;
        for(int j = 0; j < n; j ++)if(!vis[j] && minn > dis[j]) {
                minn = dis[j];
                u = j;
            }
        vis[u] = 1;
        int sz = g[u].size();
        for(int j = 0; j < sz; j ++) {
            int v = g[u][j].first;
            int w = g[u][j].second;
            if(!vis[v] && dis[v] > w) dis[v] =  w;
        }
    }
}
char u[5], v[5];
int main() {
    int k, w, n;
    while(scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < n; i ++)g[i].clear();
        for(int i = 0; i < n - 1; i ++) {
            scanf("%s%d", u, &k);
            while(k --) {
                scanf("%s%d", v, &w);
                g[u[0] - 'A'].push_back(make_pair(v[0] - 'A', w));
                g[v[0] - 'A'].push_back(make_pair(u[0] - 'A', w));
            }
        }
        prim(0, n);
        int ans = 0;
        for(int i = 0; i < n; i ++)
            ans += dis[i];

        printf("%d\n", ans);
    }
    return 0;
}
