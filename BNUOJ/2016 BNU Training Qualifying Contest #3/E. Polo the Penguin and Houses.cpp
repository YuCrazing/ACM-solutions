#include <cstdio>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){ // Brute Force
    int n, k;
    scanf("%d%d", &n, &k);
    ll res = 1;
    for(int i = k + 1; i <= n; i ++) res  = res * (n - k) % MOD;
    for(int i = 1; i < k; i ++) res = res * k % MOD;
    printf("%lld\n", res);
    return 0;
}
