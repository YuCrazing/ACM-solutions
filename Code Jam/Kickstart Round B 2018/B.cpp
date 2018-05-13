/*
    类似数位dp:
    dp[sta][cur]表示当前做到第 cur 位（前cur位已确定）,
    第 cur-15 位到第 cur 位的状态为 sta 的方案数为多少
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mask=(1<<16)-1;
const ll inf=2e18;

ll p, dp[1<<16][101];
int T, n, k, a, b, c;
vector<pair<int, int> > v[101];

ll calc(int sta, int cur) {
    sta=sta&mask;
    ll &dpp=dp[sta][cur];
    if(dpp!=-1) return dpp;
    for(int i = 0; i < v[cur].size(); ++i) {
        int num=v[cur][i].second;
        int m=(1<<(cur-v[cur][i].first+1))-1;
        if(__builtin_popcount(sta&m)!=num) return dpp=0;
    }
    return dpp = (cur==n?1:min(calc(sta<<1, cur+1) + calc(sta<<1|1, cur+1), inf));
}

int main() {

//    freopen("B-large-practice.in", "r", stdin);
//    freopen("B-large-practice.out", "w", stdout);

    scanf("%d", &T);

    for(int ca = 1; ca <= T; ++ca) {

        scanf("%d%d%lld", &n, &k, &p);

        for(int i = 1; i <= n; ++i) v[i].clear();
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < k; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            v[b].push_back({a, c});
        }

        int sta=0;
        string s;
        for(int i = 1; i <= n; ++i) {
            ll t = calc(sta<<1, i);
            if(t >= p) {
                sta=sta<<1;
                s+='0';
            } else {
                p-=t;
                sta=sta<<1|1;
                s+='1';
            }
        }

        printf("Case #%d: %s\n", ca, s.c_str());

    }

    return 0;
}
/*
10
100 2 1024
5 10 6
1 3 3
100 0 1024
100 2 1024
5 10 6
1 3 3
100 0 1024
100 2 1024
5 10 6
1 3 3
100 0 1024
100 0 1000000000000000000
100 0 1000000000000000000
100 0 1000000000000000000

1 1 1

*/
