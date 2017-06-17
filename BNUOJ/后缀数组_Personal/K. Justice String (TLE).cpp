/*
    TLE
*/

#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;

const int N = 2e5 + 5;

int wa[N*3], wb[N*3], wv[N*3], wss[N*3], dp[N][18],sa[N*3], ra[N], height[N], jj[N];

inline int c0(int *r, int a, int b) {
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

inline int c12(int k, int *r, int a, int b) {
    if(k == 2)
        return r[a] < r[b] || (r[a] == r[b] && c12(1, r, a + 1, b + 1));
    else return r[a] < r[b] || (r[a] == r[b] && wv[a + 1] < wv[b + 1]);
}

inline void sort(int *r, int *a, int *b, int n, int m) {
    int i;
    for(i = 0; i < n; i++) wv[i] = r[a[i]];
    for(i = 0; i < m; i++) wss[i] = 0;
    for(i = 0; i < n; i++) wss[wv[i]]++;
    for(i = 1; i < m; i++) wss[i] += wss[i - 1];
    for(i = n - 1; i >= 0; i--) b[--wss[wv[i]]] = a[i];
}

void dc3(int *r, int *sa, int n, int m) {
    int i, j, *rn = r + n;
    int *san = sa + n, ta = 0, tb = (n+1)/3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for(i = 0; i < n; i++) if(i%3 != 0) wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for(p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++) {
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    }
    if(p < tbc) dc3(rn, san, tbc, p);
    else for(i = 0; i < tbc; i++) san[rn[i]] = i;
    for(i = 0; i < tbc; i++) if(san[i] < tb) wb[ta++] = san[i] * 3;
    if(n % 3 == 1) wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for(i = 0; i < tbc; i++) wv[wb[i] = G(san[i])] = i;
    for(i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for(; i < ta; p++) sa[p] = wa[i++];
    for(; j < tbc; p++) sa[p] = wb[j++];
}

void da(int str[], int n) {
    int m = 128;
    for(int i = n; i < n * 3; i++)
        str[i] = 0;
    dc3(str, sa, n + 1, m);
    int i, j, k = 0;
    for(i = 0; i <= n; i++) ra[sa[i]] = i;
    for(i = 0; i < n; i++) {
        if(k) k--;
        j = sa[ra[i] - 1];
        while(str[i + k] == str[j + k]) k++;
        height[ra[i]] = k;
    }
}

void initRMQ(int n) {
    for(int i = 2; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 2; i + (1<<j) - 1 <= n; i++) {
            int a = dp[i][j - 1];
            int b = dp[i + (1<<(j - 1))][j - 1];
            dp[i][j] = (a < b ? a : b);
        }
    }
}

void init() {
    jj[1] = 0;
    for(int i = 2; i < N; i++) jj[i] = jj[i>>1] + 1;
}

inline int lcp(int x, int y) {
    if(ra[x] > ra[y]) swap(x, y);
    x = ra[x] + 1;
    y = ra[y];
    int j = jj[y - x + 1];
    int a = dp[x][j];
    int b = dp[y - (1<<j) + 1][j];
    return (a < b ? a : b);
}

int n, m, nm, T, ca = 0;
char s[N>>1];
int t[N*3];

int calc() {
    for(int i = 0; i < m; i++) {
        if(m - i < n) break;
        int t = lcp(i, m + 1);
        if(t >= n - 2) return i;
        t += lcp(i + t + 1, m + 1 + t + 1);
        if(t >= n - 2) return i;
        t += lcp(i + t + 2, m + 1 + t + 2);
        if(t >= n - 2) return i;
    }
    return -1;
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%s", s);
        m = strlen(s);
        for(int i = 0; i < m; i++) t[i] = s[i];

        scanf("%s", s);
        n = strlen(s);
        for(int i = 0; i < n; i++) t[m + 1 + i] = s[i];

        nm = n + m + 1;
        t[m] = 1;
        t[nm] = 0;

        if(m < n) {
            printf("Case #%d: -1\n", ca);
            continue;
        }

        da(t, nm);
        initRMQ(nm);

        printf("Case #%d: %d\n", ca, calc());
    }
    return 0;
}
