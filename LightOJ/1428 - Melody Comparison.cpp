#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int L = 50005;
int T, Next[L], t1[L], t2[L], sa[L], ra[L], c[L], height[L], pos[L];

void init(){
    memset(pos, -1, sizeof(pos));
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

void KMP(char *s, int ls, char *t, int lt) {

    initKMP(s, ls);

    int j = 0;
    for(int i = 0; i < lt; i++) {
        while(j > 0 && t[i] != s[j]) j = Next[j];
        if(t[i] == s[j]) j++;

        if(j == ls) {
            pos[i - ls + 1] = i - ls + 1;
        }
    }

    pos[lt] = lt;
    for(int i = lt - 1; i >= 0; i--) if(pos[i] == -1){
        pos[i] = pos[i + 1];
    }
}

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(char *s, int n) {
    n++;
    int m = 128;

    int *x = t1, *y = t2;

    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(int i = 1; i < m; i++) c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;

    int p;
    for(int l = 1; l <= n; l <<= 1, m = p) {
        p = 0;
        for(int i = n - l; i < n; i++) y[p++] = i;
        for(int i = 0; i < n; i++) if(sa[i] >= l) y[p++] = sa[i] - l;

        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++;
        for(int i = 1; i < m; i++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y); //!!

        p = 0;
        x[sa[0]] = p++;
        for(int i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? p-1 : p++;

        if(p >= n) break;
    }

    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n - 1; i++) {
        if(k) k--;
        int j = sa[ra[i]-1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }
}

char a[L], b[L];

int main() {

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {

        init();

        scanf("%s%s", a, b);

        int la = strlen(a);
        int lb = strlen(b);
        KMP(b, lb, a, la);
        DA(a, la);

        ll ans = ll(la)*ll(la + 1) / 2;

        for(int i = 1; i <= la; i++) {
            int p = pos[sa[i]];
            if(p >= la) ans -= height[i];
            else {
                p += lb - 1;
                ans -= min(height[i] + la - p, la - sa[i]);
            }
        }

        printf("Case %d: %lld\n", ca, ans);
    }

    return 0;
}
