#include <bits/stdc++.h>
using namespace std;
typedef long double db;

const int N = 100005;
vector< tuple<int, int, int> > edges;
vector<int> g[N];
int vis[N];
int in[N], order[N], n, m;

bool nocycle(int u, int root) {
    vis[u]=root;
    bool res = false;
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(vis[v]==root) return false;
        if(vis[v]!=0) continue;
        if(nocycle(v, root)==false) return false;
    }
    vis[u]=-1;
    return true;
}

bool calc(int threshold) {
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        vis[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        int u = get<0>(edges[i]);
        int v = get<1>(edges[i]);
        int w = get<2>(edges[i]);
        if(w > threshold) {
//            printf("#%d %d %d\n", threshold, u, v);
            g[u].push_back(v);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
//            printf("%d %d\n", threshold, i);
            if(nocycle(i, i)==false) return false;
        }
    }
    return true;
}

void toposort() {
    queue<int> Q;
    for(int i = 1; i <= n; ++i) if(!in[i]) Q.push(i);
    int num = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        order[u] = ++num;
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            --in[v];
            if(in[v]==0) Q.push(v);
        }
    }
}

void bin() {
    int mx=-1;
    for(int i = 0; i < m; ++i) mx = max(mx, get<2>(edges[i]));
    int l = 0, r = mx;
    while(l<r) {
        int mid = (l+r)/2;
        if(calc(mid)) r = mid;
        else l = mid + 1;
    }

    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        vis[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        int u = get<0>(edges[i]);
        int v = get<1>(edges[i]);
        int w = get<2>(edges[i]);
        if(w > r) {
            ++in[v];
            g[u].push_back(v);
        }
    }

    toposort();

    vector<int> indices;
    for(int i = 0; i < m; ++i) {
        int u = get<0>(edges[i]);
        int v = get<1>(edges[i]);
        int w = get<2>(edges[i]);
        if(w <= r) {
            if(order[u] > order[v]) {
                indices.push_back(i+1);
            }
        }
    }
    printf("%d %d\n", r, indices.size());
    for(int i = 0; i < indices.size(); ++i) {
        printf("%d ", indices[i]);
    }

}

int main() {
    int u, v, w;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back(tuple<int, int, int>(u, v, w));
    }
    bin();
    return 0;
}
