/*
    更新 dp[i][j] 时注意取最小值

    dp[i][j] = updateVal;                      (Wrong)
    dp[i][j] = min(dp[i][j], updateVal);       (Right)
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1011;

struct Line {

    int l, r, h;

    Line(int l=0, int r=0, int h=0):l(l),r(r),h(h) {};

    bool operator<(const Line& t)const {
        return h > t.h;
    }

} line[N];

int T, n, x, y, MAX, ans, dp[N][2];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &n, &x, &y, &MAX);
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &line[i].l, &line[i].r, &line[i].h);
            if(line[i].l > line[i].r) swap(line[i].l, line[i].r);
        }
        line[n++] = Line(x, x, y);

        sort(line, line + n);

        memset(dp, -1, sizeof(dp));
        dp[0][0] = dp[0][1] = 0;

        ans = 1e9;
        for(int i = 0; i < n; i++) {
            if(dp[i][0]!=-1) {
                bool ok = true;
                for(int j = i+1; j < n; j++) {
                    if(line[j].l <= line[i].l && line[j].r >= line[i].l) {
                        ok = false;
                        int h = line[i].h - line[j].h;
                        if(h <= MAX) {
                            if(dp[j][0] == -1) dp[j][0] = dp[i][0] + h + abs(line[i].l - line[j].l);
                            else dp[j][0] = min(dp[j][0], dp[i][0] + h + abs(line[i].l - line[j].l));
                            if(dp[j][1] == -1) dp[j][1] = dp[i][0] + h + abs(line[i].l - line[j].r);
                            else dp[j][1] = min(dp[j][1], dp[i][0] + h + abs(line[i].l - line[j].r));
                        }
                        break;
                    }
                }
                if(ok && line[i].h <= MAX) ans = min(ans, dp[i][0] + line[i].h);
            }

            if(dp[i][1]!=-1) {
                bool ok = true;
                for(int j = i+1; j < n; j++) {
                    if(line[j].l <= line[i].r && line[j].r >= line[i].r) {
                        ok = false;
                        int h = line[i].h - line[j].h;
                        if(h <= MAX) {
                            if(dp[j][0] == -1) dp[j][0] = dp[i][1] + h + abs(line[i].r - line[j].l);
                            else dp[j][0] = min(dp[j][0], dp[i][1] + h + abs(line[i].r - line[j].l));
                            if(dp[j][1] == -1) dp[j][1] = dp[i][1] + h + abs(line[i].r - line[j].r);
                            else dp[j][1] = min(dp[j][1], dp[i][1] + h + abs(line[i].r - line[j].r));
                        }
                        break;
                    }
                }
                if(ok && line[i].h <= MAX) ans = min(ans, dp[i][1] + line[i].h);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
