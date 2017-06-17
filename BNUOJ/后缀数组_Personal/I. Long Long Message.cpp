#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int L = 100004*2;
int T, t1[L], t2[L], c[L], ra[L], sa[L], height[L], len[2];

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
    for(int i = 0; i < n-1; i++) {
        if(k) k--;
        int j = sa[ra[i]-1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }

}

char s[2][100005], t[L];

int main() {
    while(scanf("%s%s", s[0], s[1]) != EOF) {
        int l = 0;
        for(int i = 0; i < 2; i++) {
            strcpy(t + l, s[i]);
            len[i] = strlen(s[i]);
            l += len[i];
            t[l++] = 1-i;
        }

        DA(t, l-1);

        int ans = 0;
        for(int i = 2; i < l; i++) {
            if((sa[i-1] < len[0]&&sa[i]>len[0])||(sa[i-1] > len[0]&&sa[i]<len[0]))
                ans = max(ans, height[i]);
        }

        printf("%d\n", ans);
    }
    return 0;
}
