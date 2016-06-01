#include <cstdio>
using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {

        scanf("%d", &n);
        int pre, now, sum = 0;
        for(int i = 0; i < 2 * n; i ++) {
            scanf("%d", &now);
            if(i & 1) sum ^= (now - pre - 1);
            pre = now;
        }

        printf("Case %d: ", cas);
        if(sum) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
