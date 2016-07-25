/*
    dp[i] = answer of s[1~i].
    use Manacher method to precess all palindrome substrings, enumerate last palindrome substring.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1010;
char s[MAXN], ma[MAXN << 1];
int mp[MAXN << 1], dp[MAXN];
void Manacher(int len) {

    int l = 0;
    ma[l ++] = '$';
    ma[l ++]= '#';
    for(int i = 0; i < len; i ++) {
        ma[l ++] = s[i];
        ma[l ++] = '#';
    }
    ma[l] = 0;

    int mx = 0, id = 0;
    for(int i = 0; i < l; i ++) {
        if(mx > i) mp[i] = min(mx - i, mp[(id << 1) - i]);
        else mp[i] = 1;
        while(ma[i - mp[i]] == ma[i + mp[i]]) mp[i] ++;
        if(mx < i + mp[i]) {
            id = i;
            mx = i + mp[i];
        }
    }
}
int main() {
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s", s);
        n = strlen(s);

        Manacher(n);

        dp[0] = 0;
        for(int i = 1; i <= n; i ++) {
            dp[i] = dp[i - 1] + 1;
            int pos = 2 + ((i - 1) << 1);
            for(int j = pos - 1; j > 1; j --)
                if(mp[j] + j > pos) {
                    int t = max(((j<<1) - pos - 2 - 2) / 2 + 1, 0);
                    dp[i] = min(dp[i], dp[t] + 1);
                }
        }
        printf("Case %d: %d\n", cas, dp[n]);
    }
    return 0;
}
