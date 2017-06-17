/*
    Too Slow: 1700ms
*/

#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;

const int L = 2e5 + 5;
int t1[L], t2[L], c[L], ra[L], sa[L], height[L], f[L], dp[L][20], Lg[L];

void init() {
    Lg[1] = 0;
    for(int i = 2; i < L; i++) Lg[i] = Lg[i>>1] + 1;
}

void initRMQ(int n) {
    for(int i = 2; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 2; i + (1<<j) - 1 <= n; i++) {
            dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int x, int y) {
    int j = Lg[y - x + 1];
    return min(dp[x][j], dp[y - (1<<j) + 1][j]);
}

int lcp(int x, int y) {
    if(ra[x] > ra[y]) swap(x, y);
    return RMQ(ra[x] + 1, ra[y]);
}

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

//    for(int i = 0; i < n; i++) printf("%3d: %3d %3d %3d\n", i, sa[i], ra[i], height[i]);

}

int l, k, len[2], cnt[2][L];
char s[L>>1], t[L];
ll ans, sum[2][L];
stack<int> st;

void mk(int x, bool fi) {

    int id = (sa[x] < len[0] ? 0 : 1);

    if(fi) {
        cnt[id][x] = 1;
        cnt[1-id][x] = 0;
        sum[id][x] = 0;
        sum[1-id][x] = 0;
        st.push(x);
        return;
    }

    cnt[id][x] = cnt[id][x-1] + 1;
    cnt[1-id][x] = cnt[1-id][x-1];

    while(!st.empty()) {
        int u = st.top();
        if(height[u] >= height[x]) st.pop();
        else break;
    }

    if(st.empty()) {
        sum[id][x] = ll(cnt[1-id][x-1]) * ll(height[x] - k + 1);
        sum[1-id][x] = ll(cnt[id][x-1]) * ll(height[x] - k + 1);
    } else {
        int u = st.top();
        sum[id][x] = ll(cnt[1-id][x-1] - cnt[1-id][u]) * ll(height[x] - k + 1);
        sum[1-id][x] = ll(cnt[id][x-1] - cnt[id][u]) * ll(height[x] - k + 1);

        int uid = (sa[u] < len[0] ? 0 : 1);

        if(id == uid) {
            sum[id][x] += sum[id][u];
            sum[1-id][x] += sum[1-id][u] + lcp(sa[x], sa[u]) - k + 1;
        } else {
            sum[id][x] += sum[id][u] + lcp(sa[x], sa[u]) - k + 1;
            sum[1-id][x] += sum[1-id][u];
        }
    }

    st.push(x);
    ans += sum[id][x];
}

void calc() {

    while(!st.empty()) st.pop();

    cnt[0][1] = cnt[1][1] = 0;
    ans = 0;
    bool fi;
    int i = 2;
    while(i < l) {
        fi = true;
        while(height[i] >= k && i < l) {
            if(fi) {
                mk(i-1, true);
                fi = false;
            }
            mk(i, false);
            i++;
        }
        i++;
    }
}

int main() {

    init();

    while(scanf("%d", &k) != EOF) {
        if(!k) break;

        l = 0;
        for(int i = 0; i < 2; i++) {
            scanf("%s", s);
            len[i] = strlen(s);
            strcpy(t + l, s);
            l += len[i];
            t[l++] = 1-i;
        }

        DA(t, l - 1);
        initRMQ(l - 1);

        calc();

        printf("%lld\n", ans);

    }
    return 0;
}
