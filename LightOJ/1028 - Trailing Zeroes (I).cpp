#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
int isp[MAXN];
int prime[MAXN], cnt;
void init() {
    cnt = 0;
    for(int i = 0; i < MAXN; i ++) isp[i] = 1;
    for(int i = 2; i < MAXN; i ++)if(isp[i]) {
            prime[cnt ++] = i;
            if((ll)i * (ll)i >= MAXN) continue;
            for(int j = i * i; j < MAXN;  j += i) isp[j] = 0;   //pruning
        }
}

int main() {
    int T;
    ll n, res;
    scanf("%d", &T);
    init();
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%lld", &n);
        res = 1;
        for(int i = 0; i < cnt; i++) {
            if((ll)prime[i] * (ll)prime[i] > n) break; //pruning
            int k = 0;
            while(n % prime[i] == 0) {
                k ++;
                n /= prime[i];
            }
            res *= (k + 1);
        }
        if(n > 1) res <<= 1;
        printf("Case %d: %lld\n", cas, res - 1);
    }
    return 0;
}
