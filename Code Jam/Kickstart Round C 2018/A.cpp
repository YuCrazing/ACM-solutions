#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N];
int vis[N], dis[N], path[N], tol;
bool inCycle[N];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        vis[i] = dis[i] = 0;
        inCycle[i] = false;
    }
    tol = 0;
}

void mark(int u, int fa) {
    vis[u] = 1;
    path[++tol] = u;

    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(v == fa) continue;
        if(vis[v] == 1) {
            int t = tol;
            while(1) {
                inCycle[path[t]] = true;
                if(path[t] == v) break;
                --t;
            }
        } else if(vis[v] == 0) mark(v, u);
    }

    --tol;
    vis[u] = 2;
}

void calc(int u, int fa) {
    dis[u] = (fa==-1 ? 0 : dis[fa] + 1);
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(fa == v) continue;
        if(inCycle[v]) continue;
        calc(v, u);
    }
}

int main() {
    int T, n, x, y;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {
        cin >> n;
        init(n);
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        mark(1, -1);
        for(int i = 1; i <= n; ++i)
            if(inCycle[i]) {
                calc(i, -1);
            }

        cout << "Case #" << ca << ":";
        for(int i = 1; i <= n; ++i) cout << " " << dis[i];
        cout << endl;
    }
    return 0;
}
