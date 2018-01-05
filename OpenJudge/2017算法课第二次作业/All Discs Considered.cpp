#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n1, n2, d, in[N], l[2], r[2];
vector<int> g[N];

void init() {
    l[0]=1;
    r[0]=n1;
    l[1]=n1+1;
    r[1]=n1+n2;
    for(int i = 1; i <= n1+n2; i++) g[i].clear();
}

int topo(int now) {

    for(int i = 1; i <= n1+n2; i++) in[i]=0;
    for(int i = 1; i <= n1+n2; i++)
        for(int j = 0; j < g[i].size(); j++)
            in[g[i][j]]++;

    queue<int> q[2];
    for(int i = l[now]; i <= r[now]; i++) if(!in[i]) q[now].push(i);
    for(int i = l[now^1]; i <= r[now^1]; i++) if(!in[i]) q[now^1].push(i);

    int ans = 2;
    while(1) {
        while(!q[now].empty()) {
            int u=q[now].front();
            q[now].pop();
            for(int i = 0; i < g[u].size(); i++) {
                int v=g[u][i];
                in[v]--;
                if(in[v]==0) {
                    if(l[now]<=v&&v<=r[now]) q[now].push(v);
                    else q[now^1].push(v);
                }
            }
        }
        now=(now^1);
        if(q[now].empty()) break;
        ans++;
    }
    return ans;
}

int main() {
    int v, u;
    while(scanf("%d%d%d", &n1, &n2, &d)!=EOF) {
        if(!n1&&!n2&&!d) break;
        init();
        while(d--) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }
        printf("%d\n", min(topo(0), topo(1)));
    }
    return 0;
}
