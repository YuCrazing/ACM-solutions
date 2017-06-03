#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 256;
int Next[N], cnt[N];

void init() {
    memset(cnt, 0, sizeof(cnt));
}

void initKMP(char *s, int n) {
    Next[0] = Next[1] = 0;
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = Next[j];
        if(s[i] == s[j]) j++;
        Next[i + 1] = j;
    }
}

char s[N];
int main() {
    while(scanf("%s", s) != EOF) {

        init();

        int l = strlen(s);
        initKMP(s, l);

        int ans = 0;
        for(int i = l; i > 0; i--) {
            cnt[i]++;
            ans = (ans + cnt[i]) % mod;
            cnt[Next[i]] = (cnt[Next[i]] + cnt[i]) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
