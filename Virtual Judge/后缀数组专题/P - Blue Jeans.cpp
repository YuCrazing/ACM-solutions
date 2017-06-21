#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 66*12;
int t1[N], t2[N], c[N], ra[N], sa[N], height[N];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(char *s, int n) {
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

int T, n, m, len[12], vis[12];
char t[N], s[66];

void proc(int x) {
    int id = lower_bound(len, len + n, sa[x] + 1) - len;
    vis[id] = 1;
}

int ok(int k) {
    bool fi;
    for(int i = 2; i <= m; i++) {
        fi = true;
        for(; i <= m && height[i] >= k; i++) {
            if(fi) {
                for(int j = 0; j < n; j++) vis[j] = 0;
                proc(i-1);
                fi = false;
            }
            proc(i);
        }
        if(!fi) {
            bool find = true;
            for(int j = 0; j < n; j++) {
                if(!vis[j]) {
                    find = false;
                    break;
                }
            }
            if(find) return sa[i-1];
        }
    }
    return -1;
}

void BS() {
    int l = 0, r, pos;
    for(int i = 0; i < n; i++) r = min(r, len[i]);
    for(int i = 1; i < n; i++) len[i] += len[i-1] + 1;

    while(l < r) {
        int mid = (l + r + 1) >> 1;
        int tmp = ok(mid);
        if(tmp >= 0) {
            l = mid;
            pos = tmp;
        } else r = mid - 1;
    }
    if(l < 3) printf("no significant commonalities");
    else for(int i = pos; i < pos + l; i++) printf("%c", t[i]);
    printf("\n");
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        m = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            len[i] = strlen(s);
            for(int j = 0; j < len[i]; j++) t[m++] = s[j];
            t[m++] = n - 1 - i;
        }
        m--;

        DA(t, m);

        BS();
    }
    return 0;
}
