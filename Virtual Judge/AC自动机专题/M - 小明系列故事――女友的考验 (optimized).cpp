/*
    dp[i][j]: 走到节点i, 在自动机上位置为j时的最短路径
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int C = 53;
const double INF = 1e90;

struct Node {
    int son[C], next;
    bool bad;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].bad = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(int *s, int n) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            int &son = no[cur].son[s[i]];
            if(!son) son = newNode();
            cur = son;
        }
        no[cur].bad = true;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int nex = no[fa].next;
            if(no[nex].bad) no[fa].bad = true;
            for(int i = 0; i < C; i++) {
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
    }

} ac;

int s[10];
double x[55], y[55], dp[55][N];
double g[55][55];

double dis(int i, int j) {
    return sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
}

int main() {
    int n, m, k;
    while(scanf("%d%d", &n, &m) && (n||m)) {
        g[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
            g[0][i] = g[i][0] = g[i][i] = 0;
            for(int j = 0; j < i; j++) {
                g[i][j] = g[j][i] = dis(i, j);
            }
        }

        ac.init();

        for(int i = 0; i < m; i++) {
            scanf("%d", &k);
            for(int j = 0; j < k; j++) scanf("%d", &s[j]);
            ac.insert(s, k);
        }

        ac.bfs();


        double ans=INF;
        int s = ac.no[0].son[1];
        if(!ac.no[s].bad) {

            for(int i = 0; i <= n; i++)
                for(int j = 0; j < ac.tol; j++)
                    dp[i][j] = INF;

            dp[1][s] = 0.0;
            for(int i = 1; i < n; i++) {
                for(int j = 0; j < ac.tol; j++) {
                    if(ac.no[j].bad) continue;
                    if(dp[i][j]==INF) continue;
                    for(int k = i+1; k <= n; k++) {
                        int nex = ac.no[j].son[k];
                        if(ac.no[nex].bad) continue;
                        dp[k][nex] = min(dp[k][nex], dp[i][j]+g[i][k]);
                    }
                }
            }
            for(int i = 0; i < ac.tol; i++) if(!ac.no[i].bad) ans = min(ans, dp[n][i]);

        }

        if(ans==INF) printf("Can not be reached!\n");
        else printf("%.2f\n", ans);

    }
    return 0;
}
