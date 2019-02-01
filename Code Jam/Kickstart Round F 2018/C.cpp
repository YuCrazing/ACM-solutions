#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000LL;

inline ll add(const ll & a, const ll & b) {
    ll r = a + b;
    if(r > INF) return INF;
    return r;
}

inline ll mul(const ll & a, const ll & b) {
    if(a > INF / b) return INF;
    return a * b;
}

ll qmod(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b&1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

// 以 pre 为前缀长度为 n 的回文串个数
ll calc(string pre, int chars, int n) {

    if(pre.size() == 0 && n == 0) return 0;

    if(n < pre.size()) return 0;

    if(pre.size() <= (n+1)/2) {
        int free = (n+1)/2 - pre.size();
        return qmod(chars, free);
    }

    bool valid = true;
    for(int pos = (n+1)/2; pos <= pre.size(); ++pos) {
        int ind = pos - 1;
        if(pre[ind] != pre[n-1-ind]) {
            valid = false;
            break;
        }
    }
    if(valid) return 1;
    return 0;
}

// 以 pre 为前缀长度不超过 n 的回文串个数
ll calcSum(string pre, int chars, int n) {
    ll sum = 0;
    for(int i = pre.size(); i <= n; ++i) {
        sum = add(sum, calc(pre, chars, i));
        if(sum >= INF) return sum;
    }
    return sum;
}

string prefix;
int main() {

//    freopen("C-large-practice.in", "r", stdin);
//    freopen("C-large-practice.out", "w", stdout);

    int T, L;
    ll N, K, ans;

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {

        scanf("%d%lld%lld", &L, &N, &K);

        prefix = "";

        int threshold = 100;
        if(L == 1) {
            ans = (K <= N ? K : 0);
        } else if(K <= N) {
            ans = K;
        } else {

            if(N > threshold) {
                ll border = (N-threshold+1)/2;
                ans = border * 2;
                N -= 2*border;
                K -= 2*border; // a, aa, aaa, ... 前 2*border 个全 a 回文串无法被计算到

            } else ans = 0;

            if(calcSum(prefix, L, N) < K) { // N > threshold 时肯定足够，无需判断
                ans = 0;
            } else {
                for(int i = 1; i <= N; ++i) {
                    ll sum = 0, lasSum = 0;
                    for(char ch = 'a'; ch < 'a' + L; ++ch) {
                        lasSum = sum;
                        sum = add(sum, calcSum(prefix+ch, L, N));
                        if(sum >= K) {
                            prefix += ch;
                            break;
                        }
                    }
                    K -= lasSum;
                    K -= calc(prefix, L, i); // prefix 当前已经是一个回文串
                    if(K == 0) {
                        ans += i;
                        break;
                    }
                }
            }

        }
        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}
