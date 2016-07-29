#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20010;
int a[MAXN], t1[MAXN], t2[MAXN], c[MAXN], r[MAXN], sa[MAXN], rank[MAXN], height[MAXN];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int str[], int n, int m) {

    n ++;
    int i, j, p, *x = t1, *y = t2;
    for(int i = 0; i < m; i ++) c[i] = 0;
    for(int i = 0; i < n; i ++) c[x[i] = str[i]] ++;
    for(int i = 1; i < m; i ++) c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; i --) sa[-- c[x[i]]] = i;
    for(int j = 1; j <= n; j <<= 1) {
        p = 0;
        for(int i = n - j; i < n; i ++) y[p ++] = i;
        for(int i = 0; i < n; i ++) if(sa[i] >= j) y[p ++]= sa[i] - j;

        for(int i = 0; i < m; i ++) c[i] = 0;
        for(int i = 0; i < n; i ++) c[x[y[i]]] ++;
        for(int i = 1; i < m; i ++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i --) sa[-- c[x[y[i]]]] = y[i];

        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; i ++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p ++;
        if(p >= n) break;
        m = p;
    }
    int k = 0;
    n --;
    for(int i = 0; i <= n; i ++) rank[sa[i]] = i;
    for(int i = 0; i < n; i ++) {
        if(k) k --;
        j = sa[rank[i] - 1];
        while(str[i + k] == str[j + k]) k ++;
        height[rank[i]] = k;
    }
}
bool ok(int x, int n) {
    int maxx, minn;
    maxx = minn = sa[1];
    for(int i = 2; i <= n; i ++) {
        if(height[i] < x) {
            if(maxx - minn > x) return true;
            maxx = minn = sa[i];
        }
        if(sa[i] > maxx) maxx = sa[i];
        if(sa[i] < minn) minn = sa[i];
    }
    if(maxx - minn > x) return true;
    return false;
}
int main() {
    int n;
    while(scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        for(int i = n - 1; i > 0; i --) a[i] = a[i] - a[i - 1];
        n -- ;
        for(int i = 0; i < n; i ++) r[i] = a[i + 1] + 88;
        r[n] = 0;
        da(r, n, 88 << 1);

        int l = 3, r = MAXN;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(ok(mid, n)) l = mid;
            else r = mid - 1;
        }
        if(l < 4) l = -1;
        printf("%d\n", l + 1);

    }
    return 0;
}
