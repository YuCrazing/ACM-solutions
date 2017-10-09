#include<bits/stdc++.h>
using namespace std;

int n, s, m, no, cnt;
bool vis[105];
vector<int> g[105];
void dfs(int u){
    vis[u]=1;
    cnt++;
    for(int i = 0; i < g[u].size(); i++){
        int v=g[u][i];
        if(!vis[v] && v!=no) dfs(v);
    }
}

int solve(){
    int id=1, mi=10000;
    for(int i = 1; i <= n; i++){
        if(i!=s){
            memset(vis, 0, sizeof(vis));
            no=i;
            cnt=0;
            dfs(s);
            if(cnt<mi){
                mi=cnt;
                id=i;
            }
            //printf(" === %d %d\n", i, cnt);
        }
    }
    for(int i = 1; i <= n; i++) g[i].clear();
    return id;
}



int main(){
    int u, v;
    while(scanf("%d", &n)!=EOF&&n){
        scanf("%d%d", &s, &m);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        printf("%d\n", solve());
    }
    return 0;
}
/*

4
4
3
1 2
2 3
3 4
6
3
8
1 2
2 3
2 4
2 5
3 4
3 5
4 5
5 6
0

*/
