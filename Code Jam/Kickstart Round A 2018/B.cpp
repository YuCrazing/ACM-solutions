/*

----naive 的策略：
    选到第x大或者更大的数，则留下，否则继续选。在所有的 x 中选择一个收益期望最大的。
    问题：无法通过第 5 组样例。


----最优策略：
    记有 i 次重选机会时，收益期望是 E[i]，则求 E[k]。
    E[0] 为 sigma(v[i])/n

    有i次重选机会时，假设第一次选到的数x，接下来还有 i-1 次重选机会。
    若 E[i-1] > x，则扔掉 x，继续选，收益期望为 E[i-1]。
    若 E[i-1] < x，则保留 x，因为扔掉 x 继续选的收益期望更小。
    因此，E[i] = sigma(max(v[i], E[i-1]))/n 。

*/

#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;

db qpow(db a, int b){
    db r = 1.0;
    while(b){
        if(b&1) r = r * a;
        a *= a;
        b >>= 1;
    }
    return r;
}

const int N = 2e4 + 4;
const int K = 5e5 + 5;
ll v[N], sum[N];
db E[K];
int main(){
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
    int T, n, k;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);
        sort(v+1, v+n+1);
        sum[0] = 0;
        for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + v[i];

//        db ans = 0.0f;
//        for(int i = 1; i <= n; i++){
//            db p = qpow((i-1)*1.0 / n, k+1);
//            if(i == 1) ans = sum[n]*1.0/n;
//            else ans = max(ans, p*(sum[i-1]*1.0/(i-1))+(1-p)*((sum[n]-sum[i-1])*1.0/(n-i+1)));
//            //printf("%d %f %f %f %f %f\n", i, p, (sum[i-1]*1.0/(i-1)), 1-p, (sum[n]-sum[i-1])*1.0/(n-i+1), p*(sum[i-1]*1.0/(i-1))+(1-p)*((sum[n]-sum[i-1])*1.0/(n-i+1)));
//        }

        E[0] = sum[n] * 1.0 / n;
        for(int i = 1; i <= k; i++){
            int pos = upper_bound(v+1, v+n+1, E[i-1])-v;
            if(pos == n+1) E[i] = E[i-1];
            else E[i] = ((pos-1) * E[i-1] + sum[n] - sum[pos-1]) * 1.0 / n;
        }
        printf("Case #%d: %.10f\n", ca, E[k]);
    }

    return 0;
}
/*


5
4 0
1 2 3 4
3 1
1 10 1
3 15
80000 80000 80000
1 1
10
5 3
16 11 7 4 1

*/
