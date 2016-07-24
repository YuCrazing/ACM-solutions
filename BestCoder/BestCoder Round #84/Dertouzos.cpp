#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 2e7 + 10;
bool isp[MAXN];
int prime[MAXN], divisor[MAXN];
int ct;
void init(){
    ct = 0;
    memset(isp, 1, sizeof(isp));
    memset(divisor, 0, sizeof(divisor));
    for(int i = 2; i < MAXN;  i ++)
    if(isp[i]){
        prime[ct ++] = i;
        divisor[i] = i;
        for(ll j = (ll)i * i; j < MAXN; j += i) {
            isp[j] = 0;
            if(!divisor[j]) divisor[j] = i;
        }
    }
}
int main(){
    init();
    int T, n, d;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &d);
        n --;
        if(d < MAXN){
            int lim = min(n / d, divisor[d]);
            int pos = upper_bound(prime, prime + ct, lim) - prime;
            printf("%d\n", pos);
        }else{
            int lim = n / d;
            int res = 0;
            for(int i = 0; i < ct; i ++){
                if(lim < prime[i]) break;
                res ++;
                if(d % prime[i] == 0) break;
            }
            printf("%d\n" ,res);
        }
    }
    return 0;
}
