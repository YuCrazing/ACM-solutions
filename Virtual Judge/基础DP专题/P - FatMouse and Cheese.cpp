/*
    题意理解错误：
    每次移动只能横着走最多k步或者竖着走最多k步。
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n, k, a[N][N], dp[N][N];

void init() {
    memset(dp, -1, sizeof(dp));
}

int dfs(int x, int y) {
    int& dpp = dp[x][y];
    if(dpp!=-1)return dpp;
    dpp = 0;
    for(int i = max(0, x-k); i <= min(n-1, x+k); i++) {
        if(i==x) continue;
        if(a[i][y] > a[x][y]) dpp = max(dpp, dfs(i, y));
        if(a[i][y] > a[x][y]) dpp = max(dpp, dfs(i, y));
    }
    for(int i = max(0, y-k); i <= min(n-1, y+k); i++) {
        if(i==y) continue;
        if(a[x][i] > a[x][y]) dpp = max(dpp, dfs(x, i));
        if(a[x][i] > a[x][y]) dpp = max(dpp, dfs(x, i));
    }
    dpp += a[x][y];
    return dpp;
}

int main() {
    while(scanf("%d%d", &n, &k) != EOF) {
        if(n == -1 && k == -1) break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        init();
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}
