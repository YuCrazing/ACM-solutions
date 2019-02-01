#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

const int N = 1e5 + 2;
const ll INF = 10000000000000000LL;

struct Node {
    int s, t, d, w;
    bool operator<(const Node & tt)const {
        if(w == tt.w) return d < tt.d;
        return w < tt.w;
    }
};

bool cmp(const Node & a, const Node & b) {
    return a.s < b.s;
}

priority_queue<Node> Q;

int n, m, k;
ll dp[N][202];
int nxt[N], got[N];
Node a[N];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d%d%d%d", &a[i].s, &a[i].t, &a[i].d, &a[i].w);
    }
    sort(a, a+k, cmp);

    int cur = 0;
    for(int i = 1; i <= n; ++i) {
        while(cur <= k && a[cur].s <= i) Q.push(a[cur++]);
        while(!Q.empty() && Q.top().t < i) Q.pop();
        if(Q.empty()) {
            got[i] = 0;
            nxt[i] = i+1;
        } else {
            got[i] = Q.top().w;
            nxt[i] = Q.top().d+1;
        }
    }

    for(int i = 1; i <= n+1; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i][j] = INF;

    dp[n+1][0] = 0;

    for(int i = n; i > 0; --i) {
        dp[i][0] = got[i] + dp[nxt[i]][0];
    }

    for(int i = n; i > 0; --i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = min(dp[i][j], dp[nxt[i]][j] + got[i]);
            dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
        }
    }

    ll ans = INF;
    for(int i = 0; i <= m; ++i) ans = min(ans, dp[1][i]);

    printf("%I64d\n", ans);
    return 0;
}

