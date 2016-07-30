/*
    dp[x][l][r]:

    x: segment lenght(include l, r)
    l,r: two ends' characters.
        l,r = 0: string boundary, empty
        l,r = 1: X
        l,r = 2: O
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

int dp[N][3][3], vis[N<<1];
void init() {

    for(int x = 2; x < N; x ++)
        for(int l = 0; l < 3; l ++)
            for(int r = 0; r < 3; r ++) {
                memset(vis, 0, sizeof(vis));
                for(int i = 3; i < x - 1; i ++) {
                    vis[dp[i][l][1] ^ dp[x - i + 1][1][r]] = 1;
                    vis[dp[i][l][2] ^ dp[x - i + 1][2][r]] = 1;
                }
                if(x > 3) {
                    if(l != 1 && x > 2) vis[dp[2][l][1] ^ dp[x - 1][1][r]] = 1;
                    if(l != 2 && x > 2) vis[dp[2][l][2] ^ dp[x - 1][2][r]] = 1;

                    if(r != 1 && x > 2) vis[dp[x - 1][l][1] ^ dp[2][1][r]] = 1;
                    if(r != 2 && x > 2) vis[dp[x - 1][l][2] ^ dp[2][2][r]] = 1;
                } else if(x == 3) {
                    if(l != 1 && r != 1) vis[dp[2][l][1] ^ dp[x - 1][1][r]] = 1;
                    if(l != 2 && r != 2) vis[dp[2][l][2] ^ dp[x - 1][2][r]] = 1;
                }

                int i = 0;
                while(vis[i]) i ++;
                dp[x][l][r] = i;
//                printf("(%d %d %d) %d\n", x, l, r, i);
            }
}

char s[N];
int T, n;

int proc(int L, int R) {
    int l, r;

    if(L == -1) l = 0;
    else if(s[L] == 'X') l = 1;
    else if(s[L] == 'O') l = 2;

    if(R == n) r = 0;
    else if(s[R] == 'X') r = 1;
    else if(s[R] == 'O') r = 2;

    return dp[R - L + 1][l][r];
}

int main() {
    init();
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s", s);
        n = strlen(s);

        int step = 0;
        for(int i = 0; i < n; i ++) if(s[i] == 'X' || s[i] == 'O') step ++;
        step = step & 1; //calculate who first.

        bool over = 0;
        for(int i = 0; i < n - 1; i ++)
            if((s[i] == 'X' && s[i + 1] == 'X') || (s[i] == 'O' && s[i + 1] == 'O'))
                over = 1;

        printf("Case %d: ", cas);

        if(over) {
            if(!step) printf("Yes\n");
            else printf("No\n");
            continue;
        }

        int sg = 0;
        int las = -1;
        for(int i = 0; i < n; i ++) if(s[i] == 'O' || s[i] == 'X') {
                sg ^= proc(las, i);
                las = i;
            }
        sg ^= proc(las, n);

        if((sg && !step) || (!sg && step)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
