#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
bool a[N];
int vis[N];
vector<int> g[N];
set<int> lefts, cant;
int dfs(int u, int dep) {

    vis[u]=(dep&1)+1;
    int cnt=1;

    if(!a[u]) {
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(!vis[v]) {
                cnt += dfs(v, dep+1);
            }
        }
    } else {
        //tmp cannot be global!!!
        vector<int> tmp;
        cant.clear();

        for(int i = 0; i < g[u].size(); i++) cant.insert(g[u][i]);
        for(set<int>::iterator it = lefts.begin(); it != lefts.end(); it++) {
            if(cant.find(*it)==cant.end()) tmp.push_back(*it);
        }
        lefts=cant;

        for(int i = 0; i < tmp.size(); i++) {
            int v = tmp[i];
            if(!vis[v]) {
                cnt += dfs(v, dep+1);
            }
        }
    }

    return cnt;
}

char op[10];
int n, k, v;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s%d", op, &k);
        if(op[0]=='C') a[i]=0;
        else a[i]=1;
        for(int j = 0; j < k; j++) {
            scanf("%d", &v);
            g[i].push_back(v-1);
        }
    }
    for(int i = 0; i < n; i++) lefts.insert(i);
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            int num = dfs(i, 0);
            if(num==1) {
                ok = false;
                break;
            }
        }
    }
    if(ok) {
        for(int i = 0; i < n; i++) {
            if(vis[i]==1) printf("S");
            else printf("V");
        }
        puts("");
    } else printf("Impossible\n");
    return 0;
}
