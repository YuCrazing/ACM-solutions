/*
    首先考虑如何得到字典序最大的答案。
    记 dp[cur][time] 表示现在还剩下 time 时间，要把这些时间分配到 cur 及其右边的湖泊上。
    记忆化搜索比较好理解，也比较好写，搜索起点是 dfs(1, h*12) （将每5分钟看成一个单位）
    首先这样记状态是没有后继性的，因为每个湖泊之间相互独立。
    其次这样记状态可以方便保存字典序最大的方案（枚举在 cur 停留多长时间）。
    cost 记录最优方案时在每个湖泊停留的时间。
*/

#include<bits/stdc++.h>
using namespace std;

const int N=30;
int t[N], d[N], f[N], dp[N][200], cost[N][200], n, h, T;

int dfs(int cur, int time) {
    int& dpp=dp[cur][time];
    if(dpp!=-1) return dpp;

    for(int i = time; i >= 0; --i) {
        int ans=0;
        if(d[cur]==0) ans=f[cur]*i;
        else {
            int k = f[cur]/d[cur];
            if(i>k) ans=k*(f[cur]+f[cur]-(k-1)*d[cur])/2+f[cur]%d[cur];
            else ans=i*(f[cur]+f[cur]-(i-1)*d[cur])/2;
        }
        if(cur < n && time-i-t[cur+1] >= 0) ans+=dfs(cur+1, time-i-t[cur+1]);
        if(ans > dpp) {
            dpp=ans;
            cost[cur][time]=i;
        }
    }

    return dpp;
}
int main() {

    //freopen("out.out", "w", stdout);

    scanf("%d", &T);

    for(int ca = 1; ca <= T; ++ca) {

        scanf("%d%d", &n, &h);
        h*=12;

        for(int i = 1; i <= n; ++i) scanf("%d", &f[i]);
        for(int i = 1; i <= n; ++i) scanf("%d", &d[i]);
        for(int i = 2; i <= n; ++i) scanf("%d", &t[i]);

        memset(dp, -1, sizeof(dp));
        memset(cost, -1, sizeof(cost));
        dfs(1, h);

        printf("Case %d:\n", ca);
        int time=h, i;
        for(i = 1; i <= n; ++i) {
            printf(i==1?"%d":", %d", cost[i][time]*5);
            time -= cost[i][time] + t[i+1];
            if(time<0) break; //!!! 不能继续往右走，不判断会出现很难 debug 的错误
        }
        for(++i; i <= n; ++i) printf(", 0");
        puts("");
        printf("Number of fish expected: %d\n", dp[1][h]);

    }

    return 0;
}

/*

10
2 1
1 12
0 0
11

3 1
1 1 12
1 0 0
1 11

4 16
1 0 1 0
1 2 3 4
1 1 1

5 5
220 813 882 278 814
345 658 724 516 923
177 114 11 93

1 -177
2 -291
3 -302
4 -395
5 -395

1 -177
2 -291
3 -302
4 -491
5 -598
*/
