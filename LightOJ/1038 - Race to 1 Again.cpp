#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 3;
double f[MAXN];

double gao(int n) {
    if(f[n] >= 0) return f[n];
    int sq = sqrt(n);
    double sum = 0;
    int p = 0;
    for(int i = 1; i <= sq; i ++) {
        if(n % i == 0) {
            sum += gao(i);
            p ++;
            int j = n / i;
            if(j != i && j != n) {
                sum += gao(j);
                p ++;
            }
        }
    }
    return f[n] =  (sum + p + 1) / p; //  .
}

int main() {

    for(int i = 0; i < MAXN; i ++) f[i] = -1;
    f[1] = 0;
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        printf("Case %d: %f\n", cas, gao(n));
    }
    return 0;
}
