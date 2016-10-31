#include <cstdio>
#include <cstring>
using namespace std;

const int N = 55;
char s[N];
bool dp[N][8];

bool ok(char ch) {
    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}


void proc(int i) {

    dp[i][0] = dp[i - 1][3] | dp[i - 1][4] | dp[i - 1][5] | dp[i - 1][6] ;
    for(int j = 1; j < 3; j ++) dp[i][j] = dp[i - 1][j - 1];

    dp[i][3] = dp[i - 1][0] | dp[i - 1][1];
    for(int j = 4; j < 8; j ++) dp[i][j] = dp[i - 1][j - 1];

}
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s", s);
        memset(dp, 0, sizeof(dp));

        int n = strlen(s);
        bool bad, good;
        bad = false;
        good = false;
        if(s[0] == '?') dp[0][0] = dp[0][3] = 1;
        else if(ok(s[0])) dp[0][0] = 1;
        else dp[0][3] = 1;
        for(int i = 1; i < n; i ++) {

            if(s[i] == '?')proc(i);
            else if(ok(s[i])) {
                dp[i][0] = dp[i - 1][3] | dp[i - 1][4] | dp[i - 1][5] | dp[i - 1][6] ;
                for(int j = 1; j < 3; j ++) dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][3] = dp[i - 1][0] | dp[i - 1][1] ;
                for(int j = 4; j < 8; j ++) dp[i][j] = dp[i - 1][j - 1];
            }
            if(dp[i][2] || dp[i][7]) bad = true;
        }
        if(dp[n - 1][0]||dp[n - 1][1] || dp[n - 1][3]|| dp[n - 1][4] || dp[n - 1][5] || dp[n - 1][6]) good = true;
        printf("Case %d: ", cas);
        if(bad && !good) printf("BAD\n");
        else if(good && !bad) printf("GOOD\n");
        else printf("MIXED\n");
    }
    return 0;
}

