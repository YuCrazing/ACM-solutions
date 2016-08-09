#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 22;
char s[N], ans[N];
ll fac[N];
int num[30];

void init() {
    fac[0] = 1;
    for(int i = 1; i < 21; i ++) fac[i] = fac[i - 1] * i;
}

ll calc() {
    ll p = 0;
    ll q = 1;
    for(int i = 0; i < 26; i ++) {
        if(!num[i]) continue;
        p += num[i];
        q *= fac[num[i]];
    }
    p = fac[p];
    return p / q;
}

int main() {

    init();

    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s%d",s, &n);
        memset(num, 0, sizeof(num));
        int l = strlen(s);
        for(int i = 0; i < l; i ++) num[s[i] - 'a'] ++;

        printf("Case %d: ", cas);
        if(n > calc()) printf("Impossible\n");
        else {
            for(int x = 0;  x < l; x ++) {
                for(int i = 0; i < 26; i ++) {
                    if(!num[i]) continue;
                    num[i] --;
                    ans[x] = i + 'a';
                    ll t = calc();
                    if(t >= n) break;
                    else n -= t;
                    num[i] ++;
                }
            }
            ans[l] = 0;
            printf("%s\n", ans);
        }
    }
    return 0;
}
