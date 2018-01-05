#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

struct Node {
    int x, y;
};
Node A[N], B[N];

int a, b;
int sz[N], l[N], r[N];
int sum;
bool res;
vector<int> g[N];

void in(int n) {
    for(int i = 1; i <= n; i++) g[i].clear();
}

int init(int u, int fa) {
    sz[u]=1;
    for(int i=0; i < g[u].size(); i++) {
        int v=g[u][i];
        if(v==fa) continue;
        sz[u]+=init(v, u);
    }
    l[u]=0;
    r[u]=sz[u];
    return sz[u];
}

void dfs(int u, int fa) {
    if(!res) return;
    int suml=0;
    int sumr=0;
    for(int i = 0; i < g[u].size(); i++) {
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v, u);
        suml+=l[v];
        sumr+=r[v];
    }
    l[u]=max(l[u], suml);
    r[u]=min(r[u], sumr+1);
    //printf("%d:[%d %d]\n", u, l[u], r[u]);
    if(l[u]>r[u]) {
        res=false;
        return;
    }
}

bool ok(int x) {
    init(1, 0);

    sum=x;
    res=true;

    for(int i = 0; i < a; i++) {
        l[A[i].x]=max(A[i].y, l[A[i].x]);
        if(l[A[i].x] > r[A[i].x]) return false;
    }
    for(int i = 0; i < b; i++) {
        r[B[i].x]=min(sum-B[i].y, r[B[i].x]);
        if(l[B[i].x] > r[B[i].x]) return false;
    }

    dfs(1, 0);
    if(sum >= l[1] && sum <= r[1] && res) return true;
    return false;
}

int bs(int n) {
    //printf("n=%d\n", n);
    if(!ok(n)) return -1;
    int l=0, r=n;
    while(l<r) {
        int mid=(l+r)>>1;
        if(ok(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}

int T, n;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        in(n);
        int u, v;
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%d", &a);
        for(int i = 0; i < a; i++) scanf("%d%d", &A[i].x, &A[i].y);
        scanf("%d", &b);
        for(int i = 0; i < b; i++) scanf("%d%d", &B[i].x, &B[i].y);

        printf("%d\n", bs(n));
    }
    return 0;
}
