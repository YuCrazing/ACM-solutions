//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 25;
//bool vis[N][N];
//int n, m, x, y;
//int dx[9]={0,1,1,2,2,-1,-1,-2,-2};
//int dy[9]={0,-2,2,1,-1,2,-2,1,-1};
//
//bool ok(int a, int b){
//    return a >= 0 && a <= n && b >= 0 && b <= m;
//}
//
//long long dp[N][N];
//
//int main(){
//    scanf("%d%d%d%d", &n, &m, &x, &y);
//    for(int i = 0; i < 9; ++i) {
//        int a = x + dx[i];
//        int b = y + dy[i];
//        vis[a][b] = true;
//    }
//    dp[0][0] = 1;
//    for(int i = 0; i <= n; ++i)
//    for(int j = 0; j <= m; ++j){
//        if(i > 0) dp[i][j] += dp[i-1][j];
//        if(j > 0) dp[i][j] += dp[i][j-1];
//        if(vis[i][j]) dp[i][j]=0;
//    }
//    printf("%lld\n", dp[n][m]);
//    return 0;
//}


#include <bits/stdc++.h>

using namespace std;

#define MAXN 25

long long dp[MAXN][MAXN];

int n, m;

int dx[9] = {0, 2, 2, 1, -1, -2, -2, -1, 1};
int dy[9] = {0, -1, 1, 2, 2, 1, -1, -2, -2};

bool used(int u, int e)
{
    if (u >= 0 && u <= n && e >= 0 && e <= m) {
        return 1;
    }
    return 0;
}

bool visited[MAXN][MAXN];

int main()
{
    cin >> n >> m;
    int hx, hy;
    cin >> hx >> hy;
    for (int i = 0; i < 9; i++) {
        int v = hx + dx[i];
        int e = hy + dy[i];
        if (used(v, e)) {
            visited[v][e] = true;
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (visited[i][j] == true) {
                dp[i][j] = 0;
                continue;
            }
            if(i > 0)dp[i][j] += dp[i-1][j];
            if(j > 0)dp[i][j] += dp[i][j-1];
            //dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    printf("%lld\n", dp[n][m]);
    return 0;
}
