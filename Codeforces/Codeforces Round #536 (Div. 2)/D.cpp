/*
    典型的优先队列 bfs
*/

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

const int N = 1e5 + 5;
int n, m;
vector<int> g[N], ans;
bool vis[N];
priority_queue<int, vector<int>, greater<int> > Q;

void bfs() {
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()) {
        int u = Q.top();
        Q.pop();
        ans.push_back(u);
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if(vis[v]) continue;
            vis[v] = true;
            Q.push(v);
        }
    }
}
int main() {
    int u, v;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    for(int i = 0; i < ans.size(); ++i) printf(i==ans.size()-1?"%d\n":"%d ", ans[i]);
    return 0;
}
/*
4 3
1 2
1 3
2 4

*/
