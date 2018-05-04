#include<bits/stdc++.h>

const int N = 1011;
vector<int> g[N];

bool has[N], vis[N];

int main(){
    int n, m, k, x, T;
    for(int ca = 1; ca <= T; ca++){
        scanf("%d%d%d", &k, &n, &m);

        for(int i = 0; i < n; i++) {
            has[i] = 0;
            g[i].clear();
        }

        for(int i = 0; i < k; i++) {
            scanf("%d", &x);
            has[--x]=true;
        }

    }

    return 0;
}
