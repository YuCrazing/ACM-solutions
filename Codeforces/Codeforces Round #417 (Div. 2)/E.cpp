#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 4;
vector<int> g[N];
int a[N], num[N*200], dd[N], n, sum, nodea, nodeb;

int d;
void dfs(int u, int dep) {
    bool no = true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        no = false;
        dfs(v, dep+1);
    }
    dd[u] = dep&1;
    if(no) d = dep&1;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 2; i <= n; i++) {
        int u;
        scanf("%d", &u);
        g[u].push_back(i);
    }
    dfs(1, 0);
    ll ans = 0;
    nodea = nodeb = 0;
    for(int i = 1; i<=n; i++) if(dd[i] != d) {
            num[a[i]]++;
            nodea++;
        }
    sum = 0;
    for(int i = 1; i<=n; i++) if(dd[i] == d) {
            sum^=a[i];
            nodeb++;
        }
    if(sum == 0) {
        ans = ll(nodea)*ll(nodea - 1) / 2 + ll(nodeb)*ll(nodeb - 1) / 2;
    }
    for(int i = 1; i<=n; i++) if(dd[i] == d) {
            int t = sum^a[i];
            if(t >=0 && t<N*200) ans += num[t];
        }

    printf("%I64d\n", ans);
    return 0;
}
