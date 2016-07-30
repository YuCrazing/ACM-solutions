#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//const int N = 100;
//int dp[N];
//int dfs(int x){
//    if(dp[x] != -1) return dp[x];
//    bool vis[100];
//    memset(vis, 0, sizeof(vis));
//    for(int i = 1; i * 2 <= x; i ++){
//        vis[dfs(x - i)] = 1;
//    }
//    int i = 0;
//    while(vis[i]) i ++;
//    return dp[x] = i;
//}
//int init(){
//    memset(dp, -1, sizeof(dp));
//    for(int i = 0; i < N; i ++) printf("%d %d\n", i, dfs(i));
//}

int SG(int x) {
    while(x & 1) x >>= 1;
    return x >> 1;
}

int main() {
    int T, n, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        int sg = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &x);
            sg ^= SG(x);
        }
        printf("Case %d: ", cas);
        if(sg) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
