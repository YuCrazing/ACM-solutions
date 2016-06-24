#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int res[200000];
int main() {
    //freopen("output.txt", "w", stdout);
    int T, P, L, cnt;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &P, &L);
        cnt = 0;
        int sq = sqrt(P - L);
        for(int i = 1; i <= sq; i ++)
            if((P - L) % i == 0) {
                int b = (P - L) / i;
                if(i > L) res[cnt ++] = i;
                if(b != i && b > L) res[cnt ++] = b;
            }
        sort(res, res + cnt);
        printf("Case %d: ", cas);
        if(cnt) for(int i = 0; i < cnt; i ++) printf(i == cnt - 1 ? "%d\n" : "%d ", res[i]);
        else printf("impossible\n");
    }
    return 0;
}
