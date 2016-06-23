#include <cstdio>
#include <cmath>
using namespace std;
typedef long long unsigned llu; // important

const int MAXN = 5e6 + 3;
bool isp[MAXN];
int prime[MAXN], cnt;
llu phi[MAXN];
int main() {

    cnt = 0;
    for(int i = 2; i < MAXN; i ++) isp[i] = 1;
    for(int i = 2; i < MAXN; i ++) {
        if(isp[i]) {
            prime[cnt ++] = i;
            for(llu j = i; j * i < MAXN; j ++) isp[i * j] = 0; // ll j, or i * j overflow
        }
    }

    phi[1] = 1;
    for(int i = 2; i <= 5000000; i ++){
        if(isp[i]) phi[i] = i - 1;
        else {
            int sq = sqrt(i), p = -1;
            for(int j = 0; j < cnt; j ++){
                if(prime[j] > sq) break;
                if(i % prime[j] == 0){
                    p = prime[j];
                    break;
                }
            }

            if(p == -1) phi[1] /= 0; //

            int t = i, a = 1;
            while(t % p == 0){
                a *= p;
                t /= p;
            }
            if(t == 1) phi[i] = i - i/p; //
            else phi[i] = phi[a] * phi[i / a];
        }
    }
    for(int i = 2; i <= 5000000; i ++) {
        phi[i] *= phi[i];
        phi[i] += phi[i - 1];
    }

    int T, a, b;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &a, &b);
        printf("Case %d: %llu\n", cas, phi[b] - phi[a - 1]);
    }
    return 0;
}
