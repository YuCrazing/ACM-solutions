#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int L = 1e5 + 5;
int t1[L], t2[L], c[L], sa[L], ra[L], height[L], dp[L][20];

void initRMQ(int n) {
    for(int i = 1; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 1; (i + (1<<j)) - 1 <= n; i++) {
            dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int l, int r) {
    int j = 0;
    while((1<<j) <= r - l + 1) j++;
    j--;
    return min(dp[l][j], dp[r - (1<<j) + 1][j]);
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

        swap(x, y);

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
        while(s[i+k] == s[j+k]) k++;
        height[ra[i]] = k;
    }
//    for(int i = 0; i < n; i++) printf("%d: %d %d %d\n", i, sa[i], ra[i], height[i]);
}

char s[L];
int n, l, r, prel, prer;
int main() {
    while(scanf("%s", s) != EOF) {

        int ls = strlen(s);
        DA(s, ls);
        initRMQ(ls);

        scanf("%d", &n);

        ll l1 = 0, l2 = 0, dd = 1;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &l, &r);
            if(i) {
                int t;
                int a = min(ra[l], ra[prel]);
                int b = max(ra[l], ra[prel]);
                if(a == b) t = min(r - l, prer - prel);
                else t = min(RMQ(a+1, b), min(r - l, prer - prel));

                int x = t, d = 0;
                while(x) {
                    x /= 10;
                    d++;
                }
                dd += max(d, 1);

                l2 += r - l - t;
            } else {
                l2 += r - l;
            }
            prel = l;
            prer = r;
            l1 += r - l;
        }

        printf("%I64d %I64d\n", n + l1, dd + 2*n + l2);
    }
    return 0;
}
