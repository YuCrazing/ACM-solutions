#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(){
    int T, n, q, l, r;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &q);
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

        sort(a, a + n);

        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i ++){
            scanf("%d%d", &l, &r);
            printf("%d\n", upper_bound(a, a + n, r) - lower_bound(a, a + n, l));
        }
    }
    return 0;
}
