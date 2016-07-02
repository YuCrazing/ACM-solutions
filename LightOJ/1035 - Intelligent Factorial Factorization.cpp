#include <cstdio>
using namespace std;

bool isp[111];
int prime[111], pow[111], cnt;

void init() {
    cnt = 0;
    for(int i = 0; i < 111; i ++) isp[i] = 1;
    for(int i = 2; i <= 100; i ++)
        if(isp[i]) {
            prime[cnt ++] = i;
            for(int j = i + i; j <= 100; j +=i) isp[j] = 0;
        }
}

void solve(int n) {
    for(int i = 0; i < 100; i++) pow[i] = 0;
    for(int i = 0; i < cnt; i ++) {
        if(prime[i] > n) break;
        int t = prime[i];
        while(t <= n) {
            pow[i] += n / t;
            t *= prime[i];
        }
        if(n == 1) break;
    }

    printf("%d = ", n);
    bool first = 1;
    for(int i = 0; i < cnt; i ++) if(pow[i]) {
            if(first) {
                printf("%d (%d)", prime[i], pow[i]);
                first = !first;
            } else printf(" * %d (%d)", prime[i], pow[i]);
        }
    printf("\n");
}
int main() {
    init();
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        printf("Case %d: ", cas);
        solve(n);
    }
    return 0;
}
