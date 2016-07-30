#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 205;
char s[N];
int dp[N], vis[N], ans[N];

void init() {
    dp[0] = 0;
    for(int x = 1; x < N; x ++) {
        for(int i = 1; i <= x; i ++) {
            vis[dp[max(i - 3, 0)] ^ dp[max(x - i - 2, 0)]] = x;
        }

        int i = 0;
        while(vis[i] == x) i ++;
        dp[x] = i;
    }
}

struct Segment {
    int l, r;
    Segment(int _l = 0, int _r = 0):l(_l), r(_r) {};
} seg[N];

int main() {
    init();
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s", s);
        int l = strlen(s);
        int ct = 0;

        printf("Case %d:", cas);

        for(int i = 1; i < l - 1; i ++) if(s[i - 1] == 'X' && s[i + 1] == 'X' && s[i] == '.') ans[ct ++] = i;
        for(int i = 0; i < l - 2; i ++) if(s[i + 1] == 'X' && s[i + 2] == 'X' && s[i] == '.') ans[ct ++] = i;
        for(int i = 2; i < l; i ++) if(s[i - 2] == 'X' && s[i - 1] == 'X' && s[i] == '.') ans[ct ++] = i;

        if(ct) {
            sort(ans, ans + ct);
            ct = unique(ans, ans + ct) - ans;
            for(int i = 0; i < ct; i ++) printf(" %d", ans[i] + 1);
            printf("\n");
            continue;
        }

        int las = -3;
        for(int i = 0; i < l; i ++) {
            if(s[i] == 'X') {
                seg[ct ++] = Segment(las, i);
                las = i;
            }
        }
        seg[ct ++] = Segment(las, l + 2);
        int sg = 0;
        for(int i = 0; i < ct; i ++) sg ^= dp[max(seg[i].r - 2 - (seg[i].l + 2) - 1, 0)];

        if(sg) {
            for(int i = 0; i < ct; i ++) {
                for(int pos = seg[i].l + 3; pos <= seg[i].r - 3; pos ++) {
                    sg = dp[max(pos - (seg[i].l + 3) - 2, 0)] ^ dp[max(seg[i].r - 3 - pos - 2, 0)];
                    for(int k = 0; k < ct; k ++) {
                        if(k == i) continue;
                        sg ^= dp[max(seg[k].r - 2 - (seg[k].l + 2) - 1, 0)];
                    }
                    if(!sg) printf(" %d", pos + 1);
                }
            }
        } else printf(" 0");
        printf("\n");
    }
    return 0;
}
