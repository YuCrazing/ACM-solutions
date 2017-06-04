#include<bits/stdc++.h>
using namespace std;

const int L = 5005*3;
int T, t1[L], t2[L], c[L], ra[L], sa[L], height[L], len[3];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(char *s, int n) {
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
    int k = 0;
    for(int i = 0; i < n-1; i++) {
        if(k) k--;
        int j = sa[ra[i]-1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }

}

int l, minn;
bool vis[3];

void mk(int i) {
    if(sa[i] < len[0]) vis[0] = 1;
    else if(sa[i] > len[0] && sa[i] < len[0] + len[1] + 1) vis[1] = 1;
    else vis[2] = 1;
}

bool ok(int x) {
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
            bool valid = true;
            for(int j = 0; j < 3; j++) if(!vis[j]) {
                    valid = false;
                    break;
                }
            if(valid) return true;
        }
        i++;
    }

    if(!fi) {
        bool valid = true;
        for(int j = 0; j < 3; j++) if(!vis[j]) {
                valid = false;
                break;
            }
        if(valid) return true;
    }

    return false;
}

int BS() {
    int l = 0, r = minn;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(ok(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

char s[5005], t[L];

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        l = 0;
        minn = L;
        for(int i = 0; i < 3; i++) {
            scanf("%s", s);
            strcpy(t + l, s);
            len[i] = strlen(s);
            minn = min(minn, len[i]);
            l += len[i];
            t[l++] = 2-i;
        }

        DA(t, l-1);

        printf("Case %d: %d\n", ca, BS());
    }
    return 0;
}
