#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 111;
const int MAXM = 111 * 111;

struct CC {
    vector<int> node;
    int b, w;
    CC(int _b = 0, int _w = 0):b(_b), w(_w) {};
} cc[MAXN];

struct Edge {
    int next, to;
} edge[MAXM];

int head[MAXN], col[MAXN], dp[MAXN][MAXN], path[MAXN], tot, cct;
bool mp[MAXN][MAXN];
stack<int> st[2];

void init() {
    tot = cct = 0;
    memset(head, -1, sizeof(head));
    memset(mp, 0, sizeof(mp));
    memset(col, 0, sizeof(col));
    memset(dp, 0, sizeof(dp));
}

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot ++;

    edge[tot].to = u;
    edge[tot].next = head[v];
    head[v] = tot++;
}

bool dfs(int u, int fa) {
    bool ok = 1;
    cc[cct].node.push_back(u);
    col[u] = 3 - col[fa];
    if(col[u] == 1) cc[cct].w ++;
    else cc[cct].b ++;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(fa == v) continue;
        if(col[v] == col[u]) return false;
        if(col[v]) continue;
        ok &= dfs(v, u);
    }
    return ok;
}
int main() {
//    freopen("out.txt", "w", stdout);
    int n, u, v;
    init();
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        while(scanf("%d", &v) && v) {
            mp[i][v] = 1;
        }
    }

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j < i ; j++)
            if(mp[i][j] == 0 || mp[j][i] == 0) addedge(i, j);

    col[0] = 1;
    bool ok = 1;
    for(int i = 1; i <= n; i ++) if(!col[i]) {
            cct ++;
            if(!dfs(i, 0)) {
                ok = 0;
                break;
            }
        }

    if(!ok) printf("No solution\n");
    else {
        int C = n / 2;
        for(int i = 1; i <= cct; i ++)
            for(int j = 0; j <= C; j ++) {
                if(j >= cc[i].b && (dp[i - 1][j - cc[i].b] > 0 || i == 1)) dp[i][j] = max(dp[i][j], dp[i - 1][j - cc[i].b] + cc[i].b);
                if(j >= cc[i].w && (dp[i - 1][j - cc[i].w] > 0 || i == 1)) dp[i][j] = max(dp[i][j], dp[i - 1][j - cc[i].w] + cc[i].w);
            }

        for(int i = cct;  i > 0; i --) {
            if(dp[i][C] == dp[i - 1][C - cc[i].b] + cc[i].b) {
                path[i] = 2;
                C -= cc[i].b;
            } else {
                path[i] = 1;
                C -= cc[i].w;
            }
        }


        for(int i = 1; i <= cct; i ++) {
            int sz = cc[i].node.size();
            for(int j = 0; j < sz; j ++) {
                if(col[cc[i].node[j]] == path[i]) st[0].push(cc[i].node[j]);
                else st[1].push(cc[i].node[j]);
            }
        }

        for(int i = 0; i < 2; i ++) {
            printf("%d", st[i].size());
            while(!st[i].empty()) {
                printf(" %d", st[i].top());
                st[i].pop();
            }
            printf("\n");
        }
    }
    return 0;
}
