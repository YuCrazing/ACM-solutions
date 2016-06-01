#include <cstdio>
using namespace std;

int main() {
    int T, n, m, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &m);
        long long sum = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                scanf("%d", &x);
                if(((n + m)&1) != ((i + j)&1)) sum ^= x; // ((n + m)&1): parentheses are essential, != precedence is higher than &
            }
        }
        printf("Case %d: ", cas);
        if(sum) printf("win\n");
        else printf("lose\n");
    }
    return 0;
}
