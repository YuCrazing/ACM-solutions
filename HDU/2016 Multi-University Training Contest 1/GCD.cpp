#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100011;
int a[MAXN], dp[MAXN][20], mm[MAXN];
map<int, ll> mp;

void initRMQ(int n) {
    mm[0] = -1;
    for(int i = 1; i <= n; i ++) {
        mm[i] = ((i & (i - 1)) == 0)?mm[i - 1] + 1 : mm[i - 1];
        dp[i][0] = a[i];
    }
    for(int j = 1; j <= mm[n]; j ++)
        for(int i = 1; i + (1<<j) - 1 <= n; i ++)
            dp[i][j] = __gcd(dp[i][j - 1], dp[i + (1<<(j - 1))][j - 1]);
}

int rmq(int x, int y) {
    int k = mm[y - x + 1];
    return __gcd(dp[x][k], dp[y - (1<<k) + 1][k]);
}

int find(int l, int r, int g) {
    int s = l;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(rmq(s, mid) >= g) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int T, n, m, l, r;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        mp.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        scanf("%d", &m);
        initRMQ(n);
        for(l = 1; l <= n; l ++) {
            int g = a[l];
            int pos = l - 1, las;
            while(1) {
                las = pos;
                pos = find(l, n, g);
                int t = rmq(l,pos);
                if(mp.count(t)) mp[t] += (pos - las);
                else mp[t] = pos - las;
                if(pos == n) break;
                g = rmq(l, pos + 1);
            }
        }

        printf("Case #%d:\n", cas);
        while(m --) {
            scanf("%d%d", &l, &r);
            int t = rmq(l, r);
            printf("%d %I64d\n", t, mp[t]);
        }
    }
    return 0;
}
