#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 111;
int a[N];
int dp[10010];
int dfs(int x){
    if(dp[x] != -1) return dp[x];
    bool vis[140];
    memset(vis, 0, sizeof(vis));
    for(int i = 1; 2 * i < x; i ++){
        vis[dfs(i) ^ dfs(x - i)] = 1;
    }
    int i = 0;
    while(vis[i]) i ++;

    return dp[x] = i;
}
void init(int n){
    memset(dp, -1, sizeof(dp));
//    for(int i = 1; i <= n ; i++) printf("%d %d\n", i, dfs(i));
}
int main(){
    init(100);
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){

        scanf("%d", &n);
        int sg = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
            sg ^= dfs(a[i]);
        }
        printf("Case %d: ", cas);
        if(sg) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
