#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;
typedef long long ll;

const int L = 1e5 + 5;
int t1[L], t2[L], c[L], ra[L], sa[L], rra[L], height[L], dp[2][L][20], lex[L][20], jj[L];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(char *s, int n, int op) {
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
    if(op) for(int i = 0; i < n; i++) rra[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n-1; i++) {
        if(k) k--;
        int j = sa[ra[i]-1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }

//    for(int i = 0; i < n; i++) printf("%3d: %3d %3d %3d\n", i, sa[i], ra[i], height[i]);

}

int n;

void init() {
    jj[0] = 0;
    for(int i = 1; i < L; i++) {
        if((1<<(jj[i-1]+1)) <= i) jj[i] = jj[i-1] + 1;
        else jj[i] = jj[i-1];
    }
}

void initLex() {
    for(int i = 0; i < n; i++) lex[i][0] = i;
    for(int j = 1; (1<<j) < n; j++) {
        for(int i = 0; i + (1<<j) - 1 < n; i++) {
            if(ra[lex[i][j-1]] < ra[lex[i + (1<<(j-1))][j-1]]) lex[i][j] = lex[i][j-1];
            else  lex[i][j] = lex[i + (1<<(j-1))][j-1];
        }
    }
}

void initRMQ(int op) {
    for(int i = 2; i <= n; i++) dp[op][i][0] = height[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 2; i + (1<<j) - 1 <= n; i++) {
            dp[op][i][j] = min(dp[op][i][j-1], dp[op][i + (1<<(j-1))][j-1]);
        }
    }
}

inline int RMQ(int x, int y, int op) {
    int j = jj[y-x+1];
    return min(dp[op][x][j], dp[op][y - (1<<j) + 1][j]);
}

inline int lcp(int x, int y, int op) {
    int rx, ry;

    if(op) {
        x = n - x - 1;
        y = n - y - 1;
        if(rra[x] > rra[y]) swap(x, y);
        rx = rra[x];
        ry = rra[y];
    } else {
        if(ra[x] > ra[y]) swap(x, y);
        rx = ra[x];
        ry = ra[y];
    }

    return RMQ(rx + 1, ry, op);
}

inline int LexMin(int x, int y) {
    int j = jj[y-x+1];
    if(ra[lex[x][j]] < ra[lex[y -(1<<j) + 1][j]]) return lex[x][j];
    return lex[y -(1<<j) + 1][j];
}

char s[L], t[L];

int solve() {
    int time = 0, pos, len;
    for(int l = 1; l < n; l++) {
//        for(int i = 0; (i+1)*l < m; i++) {
        for(int i = 0; ll(i+1)*ll(l) < n; i++) {

            int x = i*l;
            int y = (i+1)*l;

            int lsuf = lcp(x, y, 0);
            int lpre = lcp(x, y, 1);

            if(lsuf < 1) continue;

            int t = (lsuf + lpre - 1) / l + 1;
            int k = (lsuf + lpre - 1) % l;

            int beg = LexMin(x - lpre + 1, x - lpre + 1 + k);
            if(t > time) {
                time = t;
                pos = beg;
                len = t*l;
            } else if(t == time) {
                if(ra[beg] < ra[pos]) {
                    pos = beg;
                    len = t*l;
                }
            }
        }
    }

    if(time <= 1) {
        int p = 0;
        for(int i = 1; i <= n; i++) {
            p = sa[i];
            break;
        }
        printf("%c", s[p]); // !!!
    } else {
        for(int i = pos; i < pos + len; i++) printf("%c", s[i]);
    }
    printf("\n");
}

int main() {

    init();

    int ca = 0;
    while(scanf("%s", s) != EOF) {
        if(!strcmp(s, "#")) break;
        if(s[0] == '#') break;

        n = strlen(s);
        for(int i = 0; i < n; i++) t[i] = s[n - 1 - i];
        t[n] = 0;
        DA(t, n, 1);
        initRMQ(1);

        reverse(t, t + n);
        DA(t, n, 0);
        initRMQ(0);
        initLex();

        printf("Case %d: ", ++ca);
        solve();
    }
    return 0;
}
/*
babab
abc

*/
