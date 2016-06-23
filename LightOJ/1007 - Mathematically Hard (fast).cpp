#include <cstdio>
using namespace std;
typedef long long unsigned llu;

const int MAXN = 5e6 + 3;
bool isp[MAXN];
llu phi[MAXN];

int main() {

    for(int i = 2; i < MAXN; i ++) {
        isp[i] = 1;
        phi[i] = i;
    }
    for(int i = 2; i < MAXN; i ++)
        if(isp[i]) {
            for(int j = i; j < MAXN;  j += i) {
                isp[j] = 0;
                phi[j] *= i - 1;
                phi[j] /= i;
            }
        }
    phi[1] = 1;
    for(int i = 2; i <= 5000000; i ++) phi[i] = phi[i] * phi[i] + phi[i - 1];

    int T, a, b;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &a, &b);
        printf("Case %d: %llu\n", cas, phi[b] - phi[a - 1]);
    }
}
