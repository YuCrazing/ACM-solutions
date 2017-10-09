/*
    WA
*/

#include<bits/stdc++.h>
using namespace std;

const int N=3003;
int n, m, q, fa[N][12], d[N], ok[N];
vector<int> g[N];

struct Node {
    int s, t, k, id, ans;
    void read() {
        scanf("%d%d%d", &s, &t, &k);
    }
} a[400005];

bool cmp1(const Node &a, const Node &b) {
    return a.s<b.s;
}

bool cmp2(const Node &a, const Node &b) {
    return a.id<b.id;
}

bool cycle;
stack<int> st;
void dfs(int u, int f, int dep) {
    //printf("u=%d\n", u);
    if(ok[u]==2) {
        cycle=true;
        st.push(u);
        return;
    }
    if(ok[u]!=0) return;
    //if(cycle) printf("u=%d\n",u);
    if(cycle) ok[u]=-1;
    else ok[u]=2;
    fa[u][0]=f;
    d[u]=dep;
    for(int i = 0; i < g[u].size(); i++) {
        int v=g[u][i];
        dfs(v, u, dep+1);
    }
    if(cycle&&u==st.top()) {
        st.pop();
        if(st.empty()) cycle=false;
    }
    if(ok[u]==2) ok[u]=1;
}

void proc() {
    for(int j = 1; j < 12; j++) {
        for(int i = 1; i <= n; i++) {
            if(ok[i]==1) fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
}

int getfa(int u, int x) {
    for(int i = 0; x && i < 12; i++) {
        if(x&1) u=fa[u][i];
        x>>=1;
    }
    assert(!x);
    return u;
}


void init() {
    for(int i = 1; i <= n; i++) ok[i]=0;
    cycle=false;
    while(!st.empty()) st.pop();
}

void solve(int s) {
    init();
    dfs(s, s, 0);
    proc();
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("out1.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    int u,v;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());

    for(int i = 0; i < q; i++) {
        a[i].read();
        a[i].id=i;
    }

    sort(a, a+q, cmp1);

    int las=-1;
    for(int i = 0; i < q; i++) {
        if(las!=a[i].s) {
            solve(a[i].s);
            las=a[i].s;
        }
        //printf("%d %d %d\n", a[i].s, a[i].t, a[i].k);
        //for(int i = 1; i <= n; i++) printf("ok[%d] = %d\n", i, ok[i]);
        if(ok[a[i].t]==1 && d[a[i].t]+1>=a[i].k) a[i].ans=getfa(a[i].t, d[a[i].t]-a[i].k+1);
        else a[i].ans=-1;
    }

    sort(a, a+q, cmp2);
    for(int i = 0; i < q; i++) printf("%d\n", a[i].ans);

    return 0;
}

/*

6 10 1
2 1
2 5
3 4
4 1
4 3
4 6
5 1
5 2
6 4
6 5
6 2 2

5 10 1
1 2
1 4
1 5
2 3
3 2
3 5
4 3
4 5
5 2
5 3
1 4 2

*/
