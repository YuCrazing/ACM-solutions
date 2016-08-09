#include <cstdio>
#include <cstring>
using namespace std;
//typedef long long ll;

const int N = 202;
const int mod = 1e9 + 7;

inline void update(int & x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

int dp[N][1<<13];
int main() {
    int k;
    scanf("%d", &k);

    int dst = 1 << (2*k + 1);

    dp[0][0] = 1;
    for(int i = 0; i < 200; i ++) {
        for(int s = 0; s < dst; s ++) dp[i + 1][s] = 0;
        for(int s = 0; s < dst; s ++) {
            if(dp[i][s] <= 0) continue;
            int pos, ss;
            for(int j = 1; j < 2 * k + 1; j ++) if(!(s&(1 << j))) {
                    pos = i - k + j;
                    if(pos <= 0 || pos > 200) continue;
                    ss = (s|(1 << j))>>1;
                    update(dp[i + 1][ss], dp[i][s]);
                }

            pos = i + 1 + k;
            if(pos <= 0 || pos > 200) continue;
            ss = (s>>1)|(1<<(2*k));
            update(dp[i + 1][ss], dp[i][s]);
        }
    }

    for(int i = 1; i <= 200;  i ++) {
        int res = 0;
        for(int s = 0; s < (1<<(k + 1)); s ++) update(res, dp[i][s]);
        printf("%d\n", res);
    }

    return 0;
}
