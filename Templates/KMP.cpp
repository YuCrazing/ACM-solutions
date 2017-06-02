/*
* LightOJ 1255 Substring Frequency
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
int Next[N], T;

void initKMP(char *s, int l) {
    int j = 0;
    Next[1] = Next[0] = 0;
    for(int i = 1; i < l; i++) {
        while(j > 0 && s[j] != s[i]) j = Next[j];
        if(s[j] == s[i]) j++;
        Next[i + 1] = j;
    }
}

int KMP(char *s, int ls, char *t, int lt) {

    initKMP(s, ls);

    int j = 0, ans = 0;
    for(int i = 0; i < lt; i++) {
        while(j > 0 && t[i] != s[j]) j = Next[j];
        if(t[i] == s[j]) j++;
        if(j == ls) ans++;
    }
    return ans;
}

char s[N], t[N];
int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++){
        scanf("%s%s", t, s);
        int ls = strlen(s);
        int lt = strlen(t);
        printf("Case %d: %d\n", ca, KMP(s, ls, t, lt));
    }
    return 0;
}
