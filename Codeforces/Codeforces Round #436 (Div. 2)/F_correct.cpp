/*
    从这个题目学到了一个很重要的方法：
    从起点开始dfs，遇到环后，将dfs序在环后面（包括环？）所有点记为bad
*/

#include<bits/stdc++.h>
using namespace std;

const int N=3005;
const int Q=400004;

struct Node{
    int s, t, id, k;
    bool operator<(const Node &b) const{
        return s<b.s;
    }
}a[Q];

int n, m, q, dep[N], fa[N][12], ans[Q];
bool good[N], bad[N];
vector<int> g[N];

void dfs_bad(int u){
    bad[u]=true;
    for(int i = 0; i < g[u].size(); i++){
        int v=g[u][i];
        if(bad[v]) continue;
        dfs_bad(v);
    }
}

void dfs_good(int u){
    good[u]=true;
    for(int i = 0; i < g[u].size(); i++){
        int v=g[u][i];
        if(bad[v]) continue;
        if(good[v]) {
            dfs_bad(v);
            continue;
        }
        fa[v][0]=u;
        dep[v]=dep[u]+1;
        dfs_good(v);
    }
}

void getfa(){
    for(int j = 1; j < 12; j++){
        for(int i = 1; i <= n; i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
}

void solve(int s){
    memset(good, 0, sizeof(good));
    memset(bad, 0, sizeof(bad));
    dep[s]=fa[s][0]=0;
    dfs_good(s);
    getfa();
}

int calc(int t, int k){
    if(!good[t]) return -1;
    if(dep[t]+1<k) return -1;
    int x=dep[t]+1-k;
    for(int i=0; i<12;i++){
        if(!x) break;
        if(x&1) t=fa[t][i];
        x>>=1;
    }
    return t;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    int u, v;
    for(int i = 0;  i < m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
    for(int i = 0; i < q; i++){
        scanf("%d%d%d", &a[i].s, &a[i].t, &a[i].k);
        a[i].id=i;
    }
    sort(a, a+q);
    int las=-1;
    for(int i = 0; i < q; i++){
        if(las!=a[i].s){
            solve(a[i].s);
            las=a[i].s;
        }
        ans[a[i].id]=calc(a[i].t, a[i].k);
    }
    for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}
