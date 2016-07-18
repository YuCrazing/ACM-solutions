#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200003;
const int INF = 0x3f3f3f3f;

struct Node {
    int val;
};

struct Tree {
    Node node[MAXN << 2];

    void pushUp(int rt) {
        node[rt].val = min(node[rt<<1].val, node[rt<<1 |1].val);
    }

    void build(int l, int r, int rt) {
        node[rt].val = INF;
        if(l == r) return ;
        int mid = (l + r) >> 1;
        build(l, mid, rt<<1);
        build(mid + 1, r, rt<<1 | 1);
    }

    void update(int a, int x, int l, int r, int rt) {
        if(l == r) {
            node[rt].val = x;
            return ;
        }
        int mid = (l + r) >> 1;
        if(a <= mid) update(a, x, l, mid, rt<<1);
        else update(a, x, mid + 1, r, rt<<1 | 1);
        pushUp(rt);
    }

    int ask(int a, int b, int l, int r, int rt) {
        if(a <= l && b >= r) return node[rt].val;
        int res = INF;
        int mid = (l + r) >> 1;
        if(a <= mid) res = min(res, ask(a, b, l, mid, rt<<1));
        if(b > mid) res = min(res, ask(a, b, mid + 1, r, rt<<1 | 1));
        return res;
    }
} tree;

char s[MAXN];
int dp[MAXN], num[MAXN][26], k, n;

int cal(int l, int r) {
    int res = 0;
    for(int i = 0; i < 26; i ++) if(num[r][i] - num[l - 1][i] > 0) res ++;
    return res;
}

int find(int x, int i) {
    int l = 0, r = i;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(cal(mid, i) < x) r = mid - 1;
        else l = mid;
    }
    return l;
}

int main() {

    scanf("%d", &k);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    tree.build(1, n, 1);

    for(int i = 1; i <= n; i ++) {
        int t = s[i] - 'a';
        for(int j = 0; j < 26; j ++)
            if(j != t) num[i][j] = num[i - 1][j];
            else num[i][j] = num[i - 1][j] + 1;
    }


    for(int i = 0; i <= n; i ++) dp[i] = INF;
    for(int i = 1; i <= n;  i++) {
        int kind = cal(1, i);
        if(kind < k) continue;
        if(kind == k) {
            dp[i] = 1;
            tree.update(i, dp[i], 1, n, 1);
            continue;
        }

        int l = find(k + 1, i);
        int r = find(k, i) ;

        l ++;
        int minn = tree.ask(l - 1, r - 1, 1, n, 1);
        if(minn == INF) dp[i] = INF;
        else {
            dp[i] = minn + 1;
            tree.update(i, dp[i], 1, n, 1);
        }
    }
    for(int i = 1; i <= n; i ++) if(dp[i] == INF) dp[i] = -1;
    for(int i = 1; i <= n; i ++) printf((i == n) ? "%d\n" : "%d ", dp[i]);
    return 0;
}
