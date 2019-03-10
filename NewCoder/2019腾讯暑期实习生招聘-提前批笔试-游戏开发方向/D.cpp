// !!!
// dp[i][j] 表示合法的括号序列前缀方案数
// 注意 dp[i][0] 和 dp[0][i] 的初始化，必须满足【任意】前缀中左括号的个数不少于右括号的个数。

#include <bits/stdc++.h>
using namespace std;

const int N = 2505;
const int mod = 1000000007;
int dp[N][N];
int n, m, la[N], lb[N];

char a[N], b[N];

int dfs(int i, int j) {
    int & d = dp[i][j];
    if(d!=-1) return d;

    int ans = 0;
    if(la[i]+lb[j] < 0) ans = 0;
    else {
        ans = (dfs(i-1, j) + dfs(i, j-1))%mod;
    }

    return d = ans;
};

int main() {

    scanf("%s", a+1);
    scanf("%s", b+1);

    n = strlen(a+1);
    m = strlen(b+1);

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 1;

    // 这种写法不好
//    for(int i = 1; i <= n; ++i) {
//        la[i] = la[i-1];
//        if(a[i] == '(') ++la[i];
//        else --la[i];
////        if(la[i] >= 0) dp[i][0] = 1;
////        else dp[i][0] = 0; // 错误
//        if(la[i] >= 0) dp[i][0] = 1;
//        else {
//            for(; i <= n; ++i) dp[i][0] = 0; // 这部分的 la 没有初始化
//            break;
//        }
//    }
//
//    for(int i = 1; i <= m; ++i) {
//        lb[i] = lb[i-1];
//        if(b[i] == '(') ++lb[i];
//        else --lb[i];
////        if(lb[i] >= 0) dp[0][i] = 1;
////        else dp[0][i] = 0; // 错误
//        if(lb[i] >= 0) dp[0][i] = 1;
//        else {
//            for(; i <= m; ++i) dp[0][i] = 0; // 这部分的 lb 没有初始化
//            break;
//        }
//    }

    for(int i = 1; i <= n; ++i) {
        la[i] = la[i-1];
        if(a[i] == '(') ++la[i];
        else --la[i];
    }
    for(int i = 1; i <= m; ++i) {
        lb[i] = lb[i-1];
        if(b[i] == '(') ++lb[i];
        else --lb[i];
    }

    for(int i = 1; i <= n; ++i) {
        if(la[i] >= 0) dp[i][0] = 1;
        else {
            for(; i <= n; ++i) dp[i][0] = 0;
            break;
        }
    }
    for(int i = 1; i <= m; ++i) {
        if(lb[i] >= 0) dp[0][i] = 1;
        else {
            for(; i <= m; ++i) dp[0][i] = 0;
            break;
        }
    }

    printf("%d\n", dfs(n, m));

//    for(int i = 0; i <= n; ++i) {
//        for(int j = 0; j <= m; ++j) {
//            printf("dp[%2d][%2d] = %2d   ", i, j, dfs(i,j));
//        }
//        cout << endl;
//    }

    return 0;
}



/*

(()
())


(((((
)))))

(
)

()((
))(())

*/


