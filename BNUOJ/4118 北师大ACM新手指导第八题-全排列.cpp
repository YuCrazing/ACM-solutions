#include<bits/stdc++.h>
using namespace std;

int n, a[10], vis[10];
void dfs(int now) {
    if(now > n) {
        for(int i = 1; i <= n; i++) printf(i == n ? "%d\n" : "%d", a[i]);
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        a[now] = i;
        dfs(now + 1);
        vis[i] = 0;
    }
}
int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
