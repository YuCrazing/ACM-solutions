#include<bits/stdc++.h>
using namespace std;

const int N=1011;
const int INF=1e9;

vector<pair<int,int> > g[2][N];
bool vis[N], has[N];
int cnt[N], path[N], dis[N], tol;
queue<int> q;

void init(int n) {
    for(int i = 0; i < n; i++) {
        g[0][i].clear();
        g[1][i].clear();
        has[i]=false;
    }
    tol=0;
}

bool spfa(int s, int n) {
    for(int i = 0; i < n; i++) {
        vis[i]=cnt[i]=0;
        dis[i]=INF;
    }
    while(!q.empty()) q.pop();

    dis[s]=0;
    q.push(s);
    vis[s]=has[s]=true;
    cnt[s]++;

    int cur=-1;

    while(!q.empty()) {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i = 0; i < g[0][u].size(); i++) {
            int v=g[0][u][i].first;
            int w=g[0][u][i].second;
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if(!vis[v]) {
                    q.push(v);
                    vis[v]=has[v]=true;
                    cnt[v]++;
                    if(cnt[v]>=min(n, 50)) {
                        cur=v;
                        path[tol++]=cur;
                        break;
                    }
                }
            }
        }
        if(cur!=-1) break;
    }
    if(cur==-1) return false;

//    int sta=cur;
//    //tol=0;
//    while(cur!=-1) {
//        path[tol++]=cur;
//        printf("cur=%d fa=%d, dis=%d\n", cur, fa[cur], dis[cur]);
//        cur=fa[cur];
//        if(sta==cur) break;
//    }
    return true;
}

void bfs(int n){
    for(int i = 0; i < n; i++) vis[i]=false;
    while(!q.empty()) q.pop();
    for(int i = 0; i < tol; i++) {
        q.push(path[i]);
        vis[path[i]]=true;
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i = 0; i < g[1][u].size(); i++){
            int v=g[1][u][i].first;
            if(!vis[v]){
                q.push(v);
                path[tol++]=v;
                vis[v]=true;
            }
        }
    }
    sort(path, path+tol);
}

int main() {
    int n, m, T, u, v, w;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++) {
        scanf("%d%d", &n, &m);
        init(n);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[0][u].push_back(pair<int,int>(v, w));
            g[1][v].push_back(pair<int,int>(u, w));
        }
        bool cyc=false;
        for(int i = 0; i < n; i++) {
            if(!has[i]&&spfa(i, n)) {
                cyc=true;
            }
        }
        printf("Case %d: ", ca);
        if(cyc) {
            bfs(n);
            for(int i = 0; i < tol; i++) printf(i!=tol-1?"%d ":"%d\n", path[i]);
        } else puts("impossible");
    }
    return 0;
}
