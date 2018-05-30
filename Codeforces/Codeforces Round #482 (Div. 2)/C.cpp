#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int N=3e5+5;
int n, x, y, son[N], f[N];

vector<int> g[N];

int dfs(int u, int fa){
    int sum=0;
    for(int i = 0; i < g[u].size(); ++i){
        int v=g[u][i];
        if(v==fa) continue;
        f[v]=u;
        sum += dfs(v, u);
    }
    return son[u]=sum+1;
}

int main(){
    scanf("%d%d%d", &n, &x, &y);
    int u, v;
    for(int i = 1; i < n; ++i){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x, 0);
    int cur=y;
    while(f[cur]!=x){
        cur=f[cur];
    }
    printf("%I64d\n", n*(ll)(n-1)-((son[x]-son[cur])*(ll)son[y]));
    return 0;
}
