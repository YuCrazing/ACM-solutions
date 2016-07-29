#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10004;
int dp[MAXN], vis[MAXN];

void init() {
    for(int x = 1; x < MAXN; x ++) {
        for(int i = 1; i * 2 < x; i ++) {
            vis[dp[i] ^ dp[x - i]] = x;
        }
        int i = 0;
        while(vis[i] == x) i ++;
        dp[x] = i;
    }
}

int main() {
    init();
    int T, n, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        int sg = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &x);
            sg ^= dp[x];
        }
        printf("Case %d: ", cas);
        if(sg) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
