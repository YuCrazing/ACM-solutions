#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<int, int> a[1011], p[1011 * 502];
int main() {
    int T, n, x, y, cnt;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        cnt = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d%d", &x, &y);
            a[i] = make_pair(x, y);
            for(int j = 0; j < i; j ++)
                p[cnt ++] = make_pair(a[i].first + a[j].first, a[i].second + a[j].second);
        }
        sort(p, p + cnt);
        ll num = 1, sum = 0;
        for(int i = 1; i < cnt; i ++) {
            if(p[i] != p[i - 1]) {
                sum += (num - 1) * num / 2;
                num = 1;
            } else num ++;
        }
        sum += (num - 1) * num / 2;
        printf("Case %d: %lld\n", cas, sum);
    }
    return 0;
}
