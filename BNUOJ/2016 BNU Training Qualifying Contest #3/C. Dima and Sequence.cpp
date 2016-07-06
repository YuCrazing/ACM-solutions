#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

//int f[10000];
//int dfs(int n){
//    if(f[n] != -1) return f[n];
//    if(n & 1) return f[n] = dfs(n / 2) + 1;
//    return f[n] = dfs(n / 2);
//}
//
//void init() {
//    memset(f, -1, sizeof(f));
//    f[0] = 0;
//    for(int i = 0; i < 50; i ++) printf("%d %d\n", i, dfs(i));
//}
int a[40];
int main() {
    int n, x;
//    init();
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i ++) {
        scanf("%d", &x);
        int cnt = 0;
        while(x) {
            if(x & 1) cnt ++;
            x >>= 1;
        }
        a[cnt] ++;
    }
    ll sum = 0;
    for(int i = 0; i < 40; i ++) sum += ((ll)a[i] * (ll)(a[i] - 1)) / 2;
    printf("%lld\n", sum);
    return 0;
}
