#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 55;
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

int T, n, m, len[11], pos[11][2];
char s[10011], t[N];

void proc(int x) {
    int id = lower_bound(len, len + n, sa[x] + 1) - len;
    pos[id][0] = min(pos[id][0], sa[x]);
    pos[id][1] = max(pos[id][1], sa[x]);
}

bool ok(int k) {
    bool fi;
    for(int i = 2; i <= m; i++) {
        fi = true;
        for(; i <= m && height[i] >= k; i++) {
            if(fi) {
                for(int j = 0; j < n; j++) {
                    pos[j][0] = N;
                    pos[j][1] = -1;
                }
                proc(i-1);
                fi = false;
            }
            proc(i);
        }
        if(!fi) {
            bool find = true;
            for(int j = 0; j < n; j++) {
                if(pos[j][1] - pos[j][0] < k) {
                    find = false;
                    break;
                }
            }
            if(find) return true;
        }
    }
    return false;
}

int BS() {
    int l = 0, r = N;
    for(int i = 0; i < n; i++) r = min(r, len[i]/2);
    for(int i = 1; i < n; i++) len[i] += len[i-1] + 1;

    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(ok(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        m = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", s);

            int j = 0;
            while(s[j] != ' ' && s[j]) j++;
            if(s[j] == ' ') s[j] = 0;

            len[i] = strlen(s);
            strcpy(t + m, s);
            m += len[i];
            t[m++] = n - 1 - i;
        }
        m--;

        DA(t, m);

        printf("%d\n", BS());
    }
    return 0;
}
