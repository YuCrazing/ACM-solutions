#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 2;
int n, m, T, a[N][2], c[N][2];
ll ans;

void init() {
    memset(c, 0, sizeof(c));
}

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int op) {
    for(int i = x; i <= n + m; i += lowbit(i)) {
        c[i][op]++;
    }
}

ll ask(int x, int op) {
    ll res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        res += c[i][op];
    }
    return res;
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);
        init();
        int x, y;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d",&x, &y);
            a[x][0] = y;
            a[x][1] = 0;
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d%d",&x, &y);
            a[x][0] = y;
            a[x][1] = 1;
        }
        ans = 0;
        for(int i = 1; i <= n + m; i++) {
            int op = a[i][1];
            ans += ask(n + m, op ^ 1) -  ask(a[i][0] - 1, op ^ 1);
            add(a[i][0], op);
        }
        printf("Case %d: %lld\n", ca, ans);
    }
    return 0;
}
