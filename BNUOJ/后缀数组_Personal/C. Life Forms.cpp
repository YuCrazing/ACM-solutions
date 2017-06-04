#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int L = 1005;
const int N = 105;
int t1[L*N], t2[L*N], c[L*N], ra[L*N], sa[L*N], height[L*N], len[N], sum[N];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(int *s, int n) {
    n++;
    int m = 400;
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
    int k = 0;
    for(int i = 0; i < n-1; i++) {
        if(k) k--;
        int j = sa[ra[i]-1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }

//    for(int i = 0; i < n; i++) printf("%d: %d %d %d %d\n", i, sa[i], ra[i], height[i], s[i]);

}

int l, minn, n, tol, pos[L*N];
bool vis[N];

void mk(int x) {
    for(int i = 0; i < n; i++) {
        if(sa[x] < sum[i]) {
            vis[i] = 1;
            return;
        }
    }
}

bool ok(int x, int op) {
    if(!x) return true;

    int i = 2;
    bool fi;
    while(i < l) { // i < l !!
        fi = true;
        while(height[i] >= x && i < l) {
            if(fi) {
                memset(vis, 0, sizeof(vis));
                mk(i - 1);
                mk(i);
                fi = false;
            } else mk(i);
            i++;
        }
        if(!fi) {
            int cnt = 0;
            for(int j = 0; j < n; j++) if(vis[j]) {
                    cnt++;
                }
            if(cnt > n/2) {
                if(op) pos[tol++] = sa[i-1];
                else return true;
            }
            fi = true;
        }
        i++;
    }

    return false;
}

int BS() {
    int l = 0, r = minn;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(ok(mid, 0)) l = mid;
        else r = mid - 1;
    }
    return l;
}

char s[L];
int t[L*N];

int main() {
    bool fi = true;
    while(scanf("%d", &n) != EOF) {
        if(!n) break;

        if(!fi) printf("\n");
        else fi = false;

        l = tol = 0;
        minn = L;
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            len[i] = strlen(s);
            for(int j = 0; j < len[i]; j++) t[j + l] = s[j] + 101;
            minn = min(minn, len[i]);
            l += len[i];
            sum[i] = l;
            t[l++] = n-1-i;
        }

        if(n == 1) {
            printf("%s\n", s);
        } else {
            DA(t, l-1);
            int ans = BS();
            if(!ans) printf("?\n");
            else {
                ok(ans, 1);
                for(int i = 0; i < tol; i++) {
                    for(int j = pos[i]; j < pos[i] + ans; j++) printf("%c", t[j] - 101);
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
