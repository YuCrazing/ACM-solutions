#include<bits/stdc++.h>
using namespace std;

const int N=50005*2;
struct Point {
    int x, y, z;
    void read() {
        scanf("%d%d%d", &x, &y, &z);
    }
    bool operator<(const Point &t)const {
        if(t.x==x&&t.y==y) {
            return z<t.z;
        }
        if(t.x==x) {
            return y<t.y;
        }
        return x<t.x;
    }
};
map<Point, int> mp;
map<int, int> mp2;
vector<int> g[N], g2[N];
int n, tol=0;

int getid(const Point &t) {
    if(mp.find(t)!=mp.end()) return mp[t];
    mp[t]=tol++;
    return tol-1;
}
int vis[N];
bool cycle=false;
void dfs(int u, int fa, int ch) {
    //printf("u=%d\n", u);
    if(cycle) return;
    vis[u]=2;
    int kk=(ch?g2[u].size():g[u].size());
    for(int i = 0; i < kk; i++) {
        int v=(ch?g2[u][i]:g[u][i]);
        //if(!ch)printf("%d %d\n", u, v);
        if(v==u) continue;
        if(v==fa) continue;
        if(vis[v]==1) continue;
        if(vis[v]==2) {
            cycle=true;
            return ;
        }
        dfs(v, u, ch);
    }
    vis[u]=1;
}

void init() {
    memset(vis, 0, sizeof(vis));
    tol=0;
    cycle=false;
}
int tol2=0;
int getid2(int x,int y) {
    int k=x*1111+y;
    if(mp2.find(k)!=mp2.end()) return mp2[k];
    mp2[k]=tol2++;
    return tol2-1;
}

Point pu, pv;
int main() {
    scanf("%d", &n);
    int u,v;
    for(int i = 0; i < n; i++) {
        pu.read();
        pv.read();
        u=getid(pu);
        v=getid(pv);
        g[u].push_back(v);
        g[v].push_back(u);
        //printf("(%d %d)\n", u, v);
        u=getid2(pu.x, pu.y);
        v=getid2(pv.x, pv.y);
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    //init();
    for(int i = 0; i < tol; i++) {
        if(vis[i])continue;
        dfs(i, -1, 0);
        if(cycle) break;
    }
    int ans=0;
    if(cycle) puts("True closed chains");
    else puts("No true closed chains");
    init();
    for(int i = 0; i < tol2; i++) {
        if(vis[i]) continue;
        dfs(i, -1, 1);
        if(cycle) break;
    }
    if(cycle) puts("Floor closed chains");
    else puts("No floor closed chains");

    return 0;
}
