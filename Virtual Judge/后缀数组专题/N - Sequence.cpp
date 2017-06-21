/*
    1.  离散化

    2.  在比较第二段子串的字典序时，因为长度不一致，
        不能直接比较，要把第二段子串和第三段子串拼接后再比较
*/

#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int t1[N], t2[N], c[N], ra[N], sa[N], height[N];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(int *s, int n) {
    n++;
//    int m = 1e6 + 6; // RE
    int m = N; //

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

int n, m, t[N], s[N], ss[N];

int main() {
    while(scanf("%d", &n) != EOF) {
        assert(n >= 3);
        m = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            ss[i] = s[i];
        }
        sort(ss, ss + n);
        unique(ss, ss + n);

        for(int i = 0; i < n; i++) {
            t[m++] = lower_bound(ss, ss + n, s[i]) - ss + 1;
        }
        reverse(t, t + m);
        t[m] = 0;
        DA(t, m);
        int p1, p2;
        for(int i = 1; i <= m; i++) {
            if(sa[i] > 1) {
                p1 = m - 1 - sa[i];
                break;
            }
        }

        int p = m - 1 - p1;
        m = p;
        for(int i = 0; i < p; i++) t[m++] = t[i];
        t[m] = 0;
        DA(t, m);
        for(int i = 1; i <= m; i++) {
            if(sa[i] > 0 && sa[i] < p) {
                p2 = p - 1 - sa[i];
                break;
            }
        }

        for(int i = p1; i >= 0; i--) printf("%d\n", s[i]);
        for(int i = p1 + p2 + 1; i > p1; i--) printf("%d\n", s[i]);
        for(int i = n - 1; i > p1 + p2 + 1; i--) printf("%d\n", s[i]);

    }
    return 0;
}
/*
7
100
1
2
5
2
5
10
*/
