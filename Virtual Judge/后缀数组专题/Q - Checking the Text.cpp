/*
    DEBUG:
    生成大数据，运行时RE，
    输出 query(int a, int b) 函数参数 a, b 发现递归死循环。

    Hash 也可以解决这道题目
*/

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
int t1[N], t2[N], c[N], ra[N], sa[N], height[N], dp[N][20], Lg[N];

void init() {
    Lg[1] = 0;
    for(int i = 2; i < N; i++) Lg[i] = Lg[i>>1] + 1;
}

void initRMQ(int n) {
    for(int i = 2; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 2; i + (1<<j) - 1 <= n; i++) {
            dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
    }
}

int lcp(int x, int y) {
    if(ra[x] > ra[y]) swap(x, y);
    x = ra[x] + 1;
    y = ra[y];
    int j = Lg[y - x + 1];
    return min(dp[x][j], dp[y - (1<<j) + 1][j]);
}

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(char *s, int n) {
    n++;
    int m = 128; //

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

int n, m, nex[N];
char s[N], op[10];
vector<char> v[N];

void insert(char ch, int p) {
    if(p < 2) return;
    p--;
    int sum = 0, pos;
    for(int i = 0; i < n; i++) {
        p--;
        if(!p) {
            v[i].insert(v[i].begin(), ch);
            pos = i;
            break;
        }

        for(int j = 0; j < v[i].size(); j++) {
            p--;
            if(!p) {
                v[i].insert(v[i].begin() + j + 1, ch); //
                pos = i;
                break;
            }
        }
        if(!p) break;
    }

    if(p > 0) {
        v[n-1].push_back(ch);
        pos = n - 1;
    }

    for(int i = pos; i >= 0; i--) {
        if(nex[i] > pos) nex[i] = pos;
        else break;
    }
}

int query(int a, int b) {

    int ans = 0, lc, nexMin, x[2], nexIns[2], pi[2], pj[2];

    x[0] = a - 1;
    x[1] = b - 1;

    nexIns[0] = nex[x[0]] - x[0] + 1;
    nexIns[1] = nex[x[1]] - x[1] + 1;
    nexMin = min(nexIns[0], nexIns[1]);

    lc = (x[0] == x[1] ? n - x[0] : lcp(x[0], x[1])); // x[0] == x[1]

    if(lc < nexMin) { // <
        return lc;
    }

    ans += nexMin;
    if(nexIns[0] == nexIns[1]) {
        pi[0] = nex[x[0]];
        pi[1] = nex[x[1]];
        pj[0] = 0;
        pj[1] = 0;
    } else {
        int id = (nexIns[0] == nexMin ? 0 : 1);
        pi[id] = nex[x[id]];
        pi[1^id] = x[1^id] + nexMin;
        pj[id] = 0;
        pj[1-id] = -1;
    }

    for(; pi[0] < n && pi[1] < n; ) {

        if(pj[0] == -1 && pj[1] == -1) {
            return ans += query(pi[0] + 1, pi[1] + 1); // 未 +1 导致递归死循环
        }

        if(pj[0] == -1) {
            if(s[pi[0]] == v[pi[1]][pj[1]]) ans++;
            else return ans;
        } else if(pj[1] == -1) {
            if(s[pi[1]] == v[pi[0]][pj[0]]) ans++;
            else return ans;
        } else {
            if(v[pi[0]][pj[0]] == v[pi[1]][pj[1]]) ans++;
            else return ans;
        }

        pj[0]++;
        if(pj[0] >= v[pi[0]].size()) {
            pj[0] = -1;
            pi[0]++;
        }
        pj[1]++;
        if(pj[1] >= v[pi[1]].size()) {
            pj[1] = -1;
            pi[1]++;
        }
    }
    return ans;
}

int main() {

    init();

    while(scanf("%s", s) != EOF) {

        n = strlen(s);
        for(int i = 0; i < n; i++) {
            v[i].clear();
            nex[i] = n;
        }

        DA(s, n);
        initRMQ(n);

        int a, b, p;
        scanf("%d", &m);
        while(m--) {
            scanf("%s", op);
            if(op[0] == 'Q') {
                scanf("%d%d", &a, &b);
                printf("%d\n", query(a, b));
            } else {
                scanf("%s%d", &op, &p);
                insert(op[0], p);
            }
        }

    }

    return 0;
}
/*

abaab
5
I a 2
Q 1 3

a
100
Q 1 1

*/
