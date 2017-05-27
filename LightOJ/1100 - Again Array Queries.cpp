#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, q, T, a[N], vis[1011];

int solve(int l, int r) {
    assert(r > l);
    memset(vis, 0, sizeof(vis));
    for(int i = l; i <= r; i++) {
        if(vis[a[i]]) return 0;
        vis[a[i]]++;
    }
    int pre = 0, minn = 10000;
    for(int i = 1; i <= 1000; i++) if(vis[i]) {
            if(pre) minn = min(minn, i - pre);
            pre = i;
        }
    return minn;
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &q);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        printf("Case %d:\n", ca);
        for(int i = 0; i < q; i++) {
            int l, r, ans;
            scanf("%d%d", &l, &r);
            if(r - l > 1000) ans = 0;
            else ans = solve(l, r);
            printf("%d\n", ans);
        }
    }
    return 0;
}
