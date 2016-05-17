#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 3;
double sumLog[MAXN];
int main(){

    sumLog[0] = 0;
    for(int i = 1; i < MAXN; i++) sumLog[i] = sumLog[i-1] + log2(i);

    int T, n, base;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &base);
        printf("Case %d: %.0f\n", cas, (n <= 1 ? 1 : ceil(sumLog[n] / log2(base))));
    }
    return 0;
}
