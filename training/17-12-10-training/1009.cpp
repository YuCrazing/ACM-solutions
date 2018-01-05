#include<bits/stdc++.h>
using namespace std;

typedef long long ull;

const int N=2e5+3;

int T, n, m, num[N];
bool vis[N];
vector<pair<int,int> > g[N], e;
unordered_map<ull, int> xy, xc;
unordered_map<ull, bool> cycle, has;


ull h(int x, int y) {
    return 1LL*x*N+y;
}

void init() {
    xy.clear();
    xc.clear();
    has.clear();
    cycle.clear();


    for(int i = 1; i <= n; i++) {
        g[i].clear();
        num[i]=0;
    }
}

int root;
bool cyc;
bool get(int u, int fa) {
    vis[u]=true;
    for(int i = 0; i < g[u].size(); i++) {
        int v=g[u][i].first;
        int c=g[u][i].second;
        if(v==fa) continue;
        if(vis[v]==true) {
            root=v;
            cyc=true;
            e.push_back(pair<int,int>(u, v));
            num[c]++;
            return true;
        } else {
            bool res=get(v, u);
            if(cyc) {
                e.push_back(pair<int,int>(u, v));
                num[c]++;
                if(u==root) cyc=false;
                return true;
            }
            if(res) return true;
        }
    }
}

void getCycle() {
    root=-1;
    cyc=false;
    e.clear();
    for(int i = 1; i <= n; i++) vis[i]=false;
    get(1, 0);
    for(int i = 0; i < e.size(); i++) {
        //rintf("cycle: %d - %d\n", e[i].first, e[i].second);
        int u=min(e[i].first, e[i].second);
        int v=max(e[i].first, e[i].second);
        cycle[h(u, v)]=true;
    }

}


void dfs(int u, int v, int c){
    has[h(min(u, v), max(u, v))] = true;
    int k=u;
    for(int i=0; i < g[k].size(); i++){
        int uu=g[k][i].first;
        int vv=k;
        int cc=g[k][i].second;
        if(has.find(h(min(uu, vv), max(vv, uu))) == has.end() && cc==c){
            dfs(uu, vv, cc);
        }
    }

    k=v;
    for(int i=0; i < g[k].size(); i++){
        int uu=g[k][i].first;
        int vv=k;
        int cc=g[k][i].second;
        if(has.find(h(min(uu, vv), max(vv, uu))) == has.end() && cc==c){
            dfs(uu, vv, cc);
        }
    }
}

int cc;
int getCC() {
    cc=0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < g[i].size(); j++){
            int u=i;
            int v=g[i][j].first;
            int c=g[i][j].second;
            if(has.find(h(min(u, v), max(v, u))) == has.end()){
                cc++;
                dfs(u, v, c);
            }
        }
    }
    //printf("cc=%d\n", cc);
}

void sub(int x, int c){
    ull ha=h(x, c);
    if(xc.find(ha)!=xc.end()) xc[ha]--;
}

void add(int x, int c) {
    ull ha=h(x, c);
    if(xc.find(ha)==xc.end()) xc[ha]=1;
    else xc[ha]++;
}

int ask(int x, int c) {
    ull ha=h(x, c);
    if(xc.find(ha)==xc.end()) return 0;
    return xc[ha];
}


int main() {
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++) {
        scanf("%d%d", &n, &m);
        init();
        int u, v, c;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &u, &v, &c);
            g[u].push_back(pair<int,int>(v, c));
            g[v].push_back(pair<int,int>(u, c));
            if(v<u) swap(u, v);
            xy[h(u, v)]=c;
            add(u, c);
            add(v, c);
        }

        getCycle();
        getCC();

        printf("Case #%d:\n", ca);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &c);
            if(v<u) swap(u, v);
            int uv=h(u, v);
            int a=xy[uv];
            int b=c;
            int d=0;
            if(a!=b){
                //printf("----num[%d]=%d\n", a, num[a]);
                //printf("----num[%d]=%d\n", b, num[b]);
                unordered_map<ull, bool>::iterator it=cycle.find(uv);

                if(it!=cycle.end() && it->second==true && num[a]==e.size()){
                    num[a]--;
                    num[b]++;
                    d++;
                }else if(it!=cycle.end() && it->second==true && num[b]==e.size()-1){
                    num[a]--;
                    num[b]++;
                    d--;
                }
                else{
                    int la=ask(u, a);
                    int ra=ask(v, a);
                    int lb=ask(u, b);
                    int rb=ask(v, b);
                    if(la>1 && ra>1) d++;
                    if(la==1 && ra==1) d--;
                    if(lb>0 && rb>0) d--;
                    if(lb== 0 && rb==0) d++;
                }
                xy[uv]=b;
                sub(u, a);
                sub(v, a);
                add(u, b);
                add(v, b);
            }
            cc+=d;
            printf("%d\n", cc);
        }
    }
    return 0;
}
