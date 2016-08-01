#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 100010;
int a[N], T, n, k;

int main() {
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d", &n, &k);

        for(int i = 1; i < n; i ++)
            scanf("%d", &a[i]);

        sort(a + 1, a + n);
        reverse(a + 1, a + n);

        ll sum = 0;
        if(k >= n) {
            sum = n;
        } else {
            for(int i = 1; i < k; i ++) sum ++;
            for(int i = k; i < n; i ++) sum += a[i] + 1;
            sum ++;
        }
        printf("%I64d\n", sum);
    }
    return 0;
}
