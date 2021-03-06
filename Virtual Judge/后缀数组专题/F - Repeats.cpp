#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
int t1[N], t2[N], c[N], ra[N], sa[N], height[N], dp[N][20], Lg[N];

void init() {
    Lg[1] = 0;
    for(int i = 2; i < N; i++) Lg[i] = Lg[i>>1] + 1;
}

void initRMQ(int n) {
    for(int i = 2; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 2; i + (1<<j) - 1 <= n; i++) {
            dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
    }
}

int lcp(int x, int y) {
    if(ra[x] > ra[y]) swap(x, y);
    x = ra[x] + 1;
    y = ra[y];
    int j = Lg[y - x + 1];
    return min(dp[x][j], dp[y - (1<<j) + 1][j]);
}

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(int *s, int n) {
    n++;
    int m = 128;

    int *x = t1, *y = t2;

    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(int i = 1; i < m; i++) c[i] += c[i-1];
    for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;

    int p;
    for(int l = 1; l <= n; l <<= 1, m = p) {
        p = 0;
        for(int i = n - l; i < n; i++) y[p++] = i;
        for(int i = 0; i < n; i++) if(sa[i] >= l) y[p++] = sa[i] - l;

        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++;
        for(int i = 1; i < m; i++) c[i] += c[i-1];
        for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y);

        p = 0;
        x[sa[0]] = p++;
        for(int i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? p-1 : p++;

        if(p >= n) break;
    }
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    int k=0;
    for(int i = 0; i < n - 1; i++) {
        if(k) k--;
        int j = sa[ra[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }
//    for(int i = 0; i < n; i++) printf("%d: %d %d %d\n", i, ra[i], sa[i], height[i]);
}

int T, n, t[N];
char s[5];

int calc() {
    int time = 1;
    for(int l = 1; l < n; l++) {
        for(int i = 0; i + l < n; i += l) {
            int lc = lcp(i, i + l);
            if(lc == 0) continue;
            int m = lc % l;
            int t = lc / l + 1;
            if(m && i-(l-m) >= 0) {
                int lc2 = lcp(i-(l-m), i + l - (l-m));
                if(lc2 > l - m) t = lc2 / l + 1;
            }
            if(t > time) {
                time = t;
            }
        }
    }
    return time;
}
int main() {

    init();

    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            t[i] = s[0] - 'a' + 1; // +1
        }
        t[n] = 0;//

        DA(t, n);
        initRMQ(n);

        printf("%d\n", calc());
    }
    return 0;
}
