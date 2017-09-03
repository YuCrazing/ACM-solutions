#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int C = 55;
const double INF = 1e20;


// overflow
double getDis(int x1, int y1, int x2, int y2) {
    return sqrt((double)((double)x1-(double)x2)*(double)((double)x1-(double)x2)
                + (double)((double)y1-(double)y2)*(double)((double)y1-(double)y2));
}

double g[C][C];

struct Node {
    int next, id, dis, son[C];
    bool bad;
};

struct AC {

    Node no[N];
    double dis[N];
    bool vis[N];
    int tol;

    int newNode(int id) {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].bad = 0;
        no[tol].id = id;
        return tol++;
    }

    void init(int n) {
        tol = 0;
        newNode(0);
        for(int i = 1; i <= n; i++) {
            newNode(i);
            no[i].next = i;
        }
    }

    void insert(int *s, int n) {
        //increasing
        for(int i = 1; i < n; i++) if(s[i] <= s[i-1]) return ;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            int &son = no[cur].son[s[i]];
            if(!son) son = newNode(s[i]);
            cur = son;
        }
        no[cur].bad = 1;
    }

    double spfa(int n) {

        for(int i = 0; i <= tol; i++) {
            dis[i] = INF;
            vis[i] = 0;
        }

        queue<int> q;
        int s = (no[0].son[1] ? no[0].son[1] : 1);
        q.push(s);
        vis[s] = 1;
        dis[s] = 0;
        double ans = (no[s].id == n ? 0 : INF);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for(int i = no[u].id + 1; i <= n; i++) {
                int v = no[u].son[i];
                double w = (u == 0 ? 0 : g[no[u].id][i]);
                if(v == 0) v = i;
                if(no[v].bad) continue;
                if(dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if(i == n) ans = min(ans, dis[v]);
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        return ans;
    }

    double bfs(int n) {

        // no[1]~no[n] is similar to no[0].
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                int son = no[0].son[j];
                if(!son) no[i].son[j] = j;
                else no[i].son[j] = son;
            }
        }

        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(no[0].son[i]) q.push(no[0].son[i]);
        }
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int nex = no[fa].next;
            if(no[nex].bad) no[fa].bad = true;
            for(int i = no[fa].id + 1; i <= n; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                    continue;
                }
                no[son].next = no[nex].son[i];
                if(no[fa].bad) no[son].bad = true;
                q.push(son);
            }
        }

        double ans = spfa(n);
        if(ans == INF) ans = -1;
        return ans;
    }
} ac;

int x[N], y[N], s[10], n, m, k;

int main() {
    while(scanf("%d%d", &n, &m)) {
        if(!n && !m) break;

        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            for(int j = 1; j < i; j++) {
                g[i][j] = g[j][i] = getDis(x[i], y[i], x[j], y[j]);
            }
        }

        ac.init(n);

        for(int i = 0; i < m; i++) {
            scanf("%d", &k);
            for(int j = 0; j < k; j++) scanf("%d", &s[j]);
            ac.insert(s, k);
        }

        int ind = ac.no[0].son[1];
        double ans;
        if(ind && ac.no[ind].bad) {
            ans = -1;
        } else ans = ac.bfs(n);

        if(ans == -1) printf("Can not be reached!\n");
        else printf("%.2f\n", ans);
    }
    return 0;
}

/*

2 2
0 0
1 1
1 2
1 2

3 1
0 0
0 1
1 0
2 1 3

2 0
-2000000000 -2000000000
2000000000 2000000000

2 0
-500000000 -500000000
500000000 500000000



*/
