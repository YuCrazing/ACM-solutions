#include <cstdio>
using namespace std;
typedef long long ll;

ll A(int m, int n){
    ll res = 1;
    for(int i = n - m + 1; i <= n; i ++) res *= i;
    return res;
}

ll C[33][33];

int main(){

    for(int i = 0; i < 33; i ++) C[i][0] = 1;
    for(int i = 1; i < 33; i ++)
        for(int j = 1; j <= i; j ++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];

    int T, n, k;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &k);
        printf("Case %d: %lld\n", cas, A(k, n) * C[n][k]);
    }
    return 0;
}
