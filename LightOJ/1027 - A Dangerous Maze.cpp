#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T, n, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        int p = 0;
        int sum = 0;

        for(int i = 0; i < n; i ++) {
            scanf("%d", &x);
            if(x < 0) sum += -x;
            else {
                sum += x;
                p ++;
            }
        }

        printf("Case %d: ", cas);
        if(!p) {
            printf("inf\n");
            continue;
        }
        int g = __gcd(sum, p);
        printf("%d/%d\n", sum / g, p / g);

    }
    return 0;
}
