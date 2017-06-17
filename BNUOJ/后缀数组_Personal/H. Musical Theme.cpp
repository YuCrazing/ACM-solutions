/*
    最长不可重叠子串（二分）
*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 2e4 + 5;
int t1[N], t2[N], c[N], sa[N], ra[N], height[N];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(int *s, int n) {
    n++;
    int m = 200;

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
        int j = sa[ra[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }
//    for(int i = 0; i < n; i++) printf("%3d: %3d %3d %3d %3d\n", i, sa[i], ra[i], height[i], s[i]);
}

int s[N], a[N], n;

bool ok(int x) {
    int i = 2, mn = 1e6, mx = 0;
    bool fi;
    while(i <= n) {
        fi = true;
        while(height[i] >= x && i <= n) {
            if(fi) {
                fi = false;
                mn = min(sa[i-1], sa[i]);
                mx = max(sa[i-1], sa[i]);
            } else {
                mn = min(mn, sa[i]);
                mx = max(mx, sa[i]);
            }
            i++;
        }
        if(!fi) {
            if(mx - mn > x) return true;
        }
        i++;
    }
    return false;
}

int BS() {
    int l = 3, r = n;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(ok(mid)) l = mid;
        else r = mid - 1;
    }
    if(l < 4) return 0;
    return l + 1;
}
int main() {
    while(scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n - 1; i++) s[i] = a[i+1] - a[i] + 88;
        n--;
        s[n] = 0;

        DA(s, n);

        printf("%d\n", BS());
    }
    return 0;
}
