/*
    O(2^14*14*14) 2s可以过

    可以优化到 O(2^14*14) :
    预处理 cost[s][i] 表示已经做了的任务状态为 s ，最后一个做的是 i ，则做 i 时需要花费多少。
*/

// O(2^14*14) 0.188s

#include<bits/stdc++.h>
using namespace std;

int c[14][14], dp[1<<14], cost[1<<14][14], lg[1<<14], n, T;

int low(int x){
    return x&(-x);
}

int dfs(int s) {
    int& dpp=dp[s];
    if(dpp!=-1) return dpp;

    dpp = 1e9;
    if(s==0) return dpp=0;
    for(int i = s; i > 0; i^=low(i)) dpp = min(dpp, cost[s][lg[low(i)]]+dfs(s^low(i)));

    return dpp;
}

int getCost(int s, int cur){
    int& dpp = cost[s][cur];
    if(dpp!=-1) return dpp;
    if((s^low(s)) == 0) return dpp = c[cur][lg[low(s)]];
    return dpp = c[cur][lg[low(s)]] + getCost(s^low(s), cur);
}

int main() {
    for(int i = 0; i < 14; ++i) lg[1<<i]=i;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &c[i][j]);

        memset(cost, -1, sizeof(cost));
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; ++i)
            for(int s = 0; s < (1<<n); ++s)
                getCost(s, i);

        printf("Case %d: %d\n", ca, dfs((1<<n)-1));
    }
    return 0;
}




// O(2^14*14*14) 0.328s

//#include<bits/stdc++.h>
//using namespace std;
//
//int c[14][14], dp[1<<14], n, T;
//int dfs(int s) {
//    if(s==0) return 0;
//    int& dpp=dp[s];
//    if(dpp!=-1) return dpp;
//
//    dpp = 1e9;
//    for(int i = 0; i < n; ++i)
//        if(s&(1<<i)) {
//            int sum=0;
//            for(int j = 0; j < n; ++j)
//                if(s&(1<<j)) sum+=c[i][j];
//            dpp = min(dpp, sum+dfs(s^(1<<i)));
//        }
//
//    return dpp;
//}
//int main() {
//    scanf("%d", &T);
//    for(int ca = 1; ca <= T; ++ca) {
//        scanf("%d", &n);
//        for(int i = 0; i < n; ++i)
//            for(int j = 0; j < n; ++j)
//                scanf("%d", &c[i][j]);
//
//        memset(dp, -1, sizeof(dp));
//        printf("Case %d: %d\n", ca, dfs((1<<n)-1));
//    }
//    return 0;
//}





// O(2^14*14*14) 0.836s

//#include<bits/stdc++.h>
//using namespace std;
//
//int c[14][14], dp[1<<14][14], n, T;
//int dfs(int s, int las) {
//    int& dpp=dp[s][las];
//    if(dpp!=-1) return dpp;
//
//    dpp = 1e9;
//    int sum=0;
//    for(int i = 0; i < n; ++i) if(s&(1<<i)) sum+=c[las][i];
//
//    s^=(1<<las);
//    if(s==0) return dpp=sum;
//    for(int i = 0; i < n; ++i) if(s&(1<<i))
//        dpp = min(dpp, sum+dfs(s, i));
//
//    return dpp;
//}
//int main() {
//    scanf("%d", &T);
//    for(int ca = 1; ca <= T; ++ca) {
//        scanf("%d", &n);
//        for(int i = 0; i < n; ++i)
//            for(int j = 0; j < n; ++j)
//                scanf("%d", &c[i][j]);
//
//        memset(dp, -1, sizeof(dp));
//        int ans=1e9;
//        for(int i = 0; i < n; ++i) ans=min(ans, dfs((1<<n)-1, i));
//        printf("Case %d: %d\n", ca, ans);
//    }
//    return 0;
//}
