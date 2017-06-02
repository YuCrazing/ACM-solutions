#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;

int t1[N], t2[N], c[N], ra[N], sa[N], height[N];

bool cmp(int *x, int a, int b, int l) {
    return x[a] == x[b] && x[a + l] == x[b + l];
}

int DA(char *s, int n) {

    n++; //
    int m = 128; //

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
        for(int i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], l) ? p - 1 : p++;
        }
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

//    for(int i = 0; i < n; i++) {
//        printf("%d: %d %d %d\n", i, sa[i], ra[i], height[i]);
//    }

}

int calc(int x, int l) {
    int sum = (2*l-x+1)*x/2;
    for(int i = 2; i <= l; i++) sum -= min(height[i], x);
    return sum;
}

char s[N];
int p, q, T;
int main() {

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%s", s);
        scanf("%d%d", &p, &q);
        int l = strlen(s);
        DA(s, l);
        printf("Case %d: %d\n", ca, calc(q, l) - calc(p - 1, l));
    }
    return 0;
}
