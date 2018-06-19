/*
    题意杀。
    题意：
    1.只有一个字符串可变时：相当于要求建一个图，满足一些限制(a, b)，表示从a能走到b，问最少多少条有向边可以满足所有限制。
    2.两个字符串都可以变时：相当于要求建一个图，满足一些限制(a, b)，表示从a能走到b或者b能走到a，问最少多少条有向边可以满足所有限制。

    对于1，考虑(a,b)构成的有向图，每一个连通块是一个DAG或者有环，记每个连通块中点数为Vi，则这个连通块至少需要Vi-1条有向边。
    如果该连通块是DAG，则只需要Vi-1条有向边（拓扑排序后连成链），否则需要Vi条边（所有点连成环）。
    对于2，同1，不同的地方在于(a,b)或(b,a)，因此可以通过调整（？），使得每个连通块都没有环，只需要Vi-1条边。

    判断每个连通块【是否有环】时，需要注意该连通块有多个环的情况容易出错，如最后一个样例。
    可以借助并查集来记录每个连通块是否有环。
*/

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=1e5+5;
bool cycle, cyc[N];
int fa[N], vis[N], a[2][N];
char s[2][50];
vector<int> g[N];

int find(int u) {
    if(u==fa[u]) return u;
    return fa[u]=find(fa[u]);
}

void merge(int u, int v) {
    int fu=find(u);
    int fv=find(v);
    fa[fu]=fv;
}

void init() {
    for(int i = 0; i < N; ++i) fa[i]=i;
}

void dfs(int u) {
    vis[u]=2;
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(vis[v]==2) cycle=true;
        else if(!vis[g[u][i]]) dfs(g[u][i]);
    }
    vis[u]=1;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int k=0; k < 2; ++k) {
        scanf("%s", s[k]);
        for(int i = 0; i < n; ++i) scanf("%d", &a[k][i]);
    }
    int ans=-1;
    if(!strcmp(s[0], "Constant") && !strcmp(s[1], "Constant")) {
        bool ok = true;
        for(int i = 0; i < n; ++i)
            if(a[0][i]!=a[1][i]) {
                ok=false;
                break;
            }
        if(ok) ans=0;
    } else if(!strcmp(s[0], "Variable") && !strcmp(s[1], "Variable")) {
        ans=0;
        init();
        for(int i = 0; i < n; ++i)
            if(a[0][i]!=a[1][i]) {
                if(find(a[0][i])!=find(a[1][i])) {
                    merge(a[0][i], a[1][i]);
                    ++ans;
                }
            }
    } else {
        if(!strcmp(s[0], "Variable")) {
            for(int i = 0; i < n; ++i) swap(a[0][i], a[1][i]);
        }
        ans=0;
        init();
        for(int i = 0; i < n; ++i)
            if(a[0][i]!=a[1][i]) {
                g[a[1][i]].push_back(a[0][i]);
                if(find(a[0][i])!=find(a[1][i])) {
                    merge(a[0][i], a[1][i]);
                    ++ans;
                }
            }
        for(int i = 0; i < N; ++i)
            if(!vis[i]) {
                cycle=false;
                dfs(i);
                if(cycle) {
                    if(!cyc[find(i)]) {
                        cyc[find(i)]=true;
                        ++ans;
                    }
                }
            }
    }
    printf("%d\n", ans);

    return 0;
}
/*

6
Constant 2 2 4 4 6 6
Constant 2 2 4 4 6 6

6
Variable 1 2 3 4 5 1
Constant 2 3 4 5 6 6

6
Variable 2 2 4 4 6 6
Variable 8 9 89 1 90 9

6
Variable 2 2 4 4 6 6
Constant 1 3 3 4 5 100000

6
Variable 2 2 4 4 6 6
Constant 100000 100000 100000 100000 100000 100000

6
Variable 100000 100000 100000 100000 100000 100000
Variable 100000 100000 100000 100000 100000 100000

3
Variable 1 2 1
Constant 2 3 3

3
Variable 1 2 1
Variable 2 3 3

5
Variable 3 4 4 1 2
Constant 4 3 1 2 1

*/
