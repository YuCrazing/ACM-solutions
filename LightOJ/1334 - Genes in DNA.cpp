#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 50005;
int Next[N], num[N], cnt[2][N], T;

void init() {
    memset(cnt, 0, sizeof(cnt));
    memset(num, 0, sizeof(num));
}

void initKMP(char *s, int l) {
    Next[0] = Next[1] = 0;
    int j = 0;
    for(int i = 1; i < l; i++) {
        while(j > 0 && s[i] != s[j]) j = Next[j];
        if(s[i] == s[j]) j++;
        Next[i + 1] = j;
    }
}

void KMP(char *s, int ls, char *t, int lt, int op) {

    initKMP(s, ls);

    /* !!! */
    num[0] = 0;
    for(int i = 1; i < ls; i++) num[i] = 1 + num[Next[i]];
    num[ls] = num[Next[ls]];

    int j = 0;
    for(int i = 0; i < lt; i++) {
        while(j > 0 && t[i] != s[j]) j = Next[j];
        if(t[i] == s[j]) j++;

        if(!op) cnt[op][i] = num[j];
        else cnt[op][lt - i - 1] = num[j];
    }
}

char s[N], t[N];
int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {

        init();

        scanf("%s%s", t, s);

        int ls = strlen(s);
        int lt = strlen(t);
        KMP(s, ls, t, lt, 0);

        reverse(s, s + ls);
        reverse(t, t + lt);
        KMP(s, ls, t, lt, 1);

        ll ans = 0;
        for(int i = 0; i < lt - 1; i++) {
            ans += ll(cnt[0][i])*ll(cnt[1][i+1]);
        }
        printf("Case %d: %lld\n", ca, ans);
    }

    return 0;
}
