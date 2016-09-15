#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 21092013;
const int N = 100010;
char S[N], T[N];
int dp[N], nexU[N], nexR[N], nexL[N];
stack<char> st;

void init() {
    while(!st.empty()) st.pop();
}

int main() {
    int tt;
    scanf("%d", &tt);
    for(int cas = 1; cas <= tt; cas ++) {


        scanf("%s", S);
        scanf("%s", T);
        int ls = strlen(S);
        int lt = strlen(T);

        init();

        for(int i = 0; i < ls; i ++) {
            if(S[i] == 'U') {
                if(st.empty()) continue;
                st.pop();
            } else st.push(S[i]);
        }

        ls = 0;
        while(!st.empty()) {
            S[ls ++] = st.top();
            st.pop();
        }
        S[ls] = 0;
//        reverse(S, S + ls);

        nexU[lt] = nexL[lt] = nexR[lt] = -1;
        for(int i = lt - 1; i >= 0; i --) {
            if(T[i] == 'U') nexU[i] = i;
            else nexU[i] = nexU[i + 1];

            if(T[i] == 'L') nexL[i] = i;
            else nexL[i] = nexL[i + 1];

            if(T[i] == 'R') nexR[i] = i;
            else nexR[i] = nexR[i + 1];
        }

        dp[lt] = 0;
        for(int i = lt - 1; i >= 0; i --) {
            if(T[i] == 'U') dp[i] = dp[i + 1];
            else {
                if(T[i] == 'L') {
                    if(nexL[i + 1] == -1) dp[i] = (2 * dp[i + 1] % mod + 1) % mod;
                    else dp[i] = (2 * dp[i + 1] % mod - dp[nexL[i + 1] + 1] + mod) % mod;
                } else {
                    if(nexR[i + 1] == -1) dp[i] = (2 * dp[i + 1] % mod + 1) % mod;
                    else dp[i] = (2 * dp[i + 1] % mod - dp[nexR[i + 1] + 1] + mod) % mod;
                }

            }
        }

        int ans = (dp[0] + 1) % mod;
        int pos = -1;

        for(int i = 0; i < ls; i ++) {

            pos = nexU[pos + 1];
            if(pos == -1) break;

            ans = (ans + 1) % mod;
            if(S[i] == 'L') {
                if(nexR[pos] == -1) continue;
                ans = (ans + 1) % mod;
                ans = (ans + dp[nexR[pos] + 1]) % mod;
            } else {
                if(nexL[pos] == -1) continue;
                ans = (ans + 1) % mod;
                ans = (ans + dp[nexL[pos] + 1]) % mod;
            }
        }

        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
/*

10000
L
LU
L
L
LR
UUUUUULR
LR
UUUUUURR

*/
