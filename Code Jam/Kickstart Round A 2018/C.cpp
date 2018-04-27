/*
    错误原因：
        x = s2[0], y = s1[0] 写成了 x = s1[0], y = s2[0]
    总结：
        命名的语义问题，x, y的变量命名在这里不合适，容易引起错误。
*/

#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;

const int L = 1e5 + 5;
const int N = 1011;
const int M = 1011;

ll A, B, C, D;
ll getNext(ll x, ll y) {
    return (A * x + B * y + C) % D;
}

int ct[M][26], len[M], sum[N][26], n, m, ch[M][2];
char s[L], s1[10], s2[10], ss[N];
ll ans;
int main() {
    freopen("C-small-practice.in", "r", stdin);
    freopen("C-small-practice.out", "w", stdout);
    int T, n, k;
    scanf("%d", &T);

    for(int ca = 1; ca <= T; ca++) {
        memset(ct, 0, sizeof(ct));
        memset(sum, 0, sizeof(sum));
        memset(len, 0, sizeof(len));
        ans = 0;
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%s", s);
            for(int j = 0; s[j]; j++) {
                ct[i][s[j]-'a'] ++;
                len[i]++;
            }
            ch[i][0] = s[0];
            ch[i][1] = s[len[i]-1];
        }
        scanf("%s%s%d%lld%lld%lld%lld", s1, s2, &n, &A, &B, &C, &D);
        sum[0][s1[0]-'a'] ++;
        sum[1][s1[0]-'a'] ++;
        sum[1][s2[0]-'a'] ++;
        ss[0] = s1[0];
        ss[1] = s2[0];
        //int i = 2, x = s1[0], y = s2[0]; !!!!!!!!!!!!!!!!!!!!!!!!!!!
        int i = 2, x = s2[0], y = s1[0];
        while(i < n) {
            ll z = getNext(x, y);
            int ass = z%26+97;
            //printf("%c\n", ass);
            memcpy(sum[i], sum[i-1], sizeof(sum[i-1]));
            sum[i][ass-'a'] ++;
            ss[i] = ass;
            y = x;
            x = z;
            i++;
        }
        //printf("%s\n", ss);

        for(int i = 0; i < m; i++) {
            for(int head = 0; head + len[i] - 1 < n; head++) {
                int tail = head + len[i] - 1;
                if(ch[i][0] != ss[head] || ch[i][1] != ss[tail]) continue;
                bool ok = true;
                for(int j = 0; j < 26; j++) {
                    //if(i==0 && !head) printf("%c %d %d\n", j+'a', ct[i][j], (head?sum[tail][j]-sum[head-1][j]:sum[tail][j]));
                    if(ct[i][j] != (head?sum[tail][j]-sum[head-1][j]:sum[tail][j])) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    //printf("i = %d\n", i);
                    ans++;
                    break;
                }
            }
        }

        printf("Case #%d: %lld\n", ca, ans);
    }

    return 0;
}

