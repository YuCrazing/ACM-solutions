#include <cstdio>
using namespace std;

int a[55];
int main() {
    int T, n, m, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &m);
        int sum = 0;
        for(int i = 0; i < n; i ++) {
            a[i] = 0;
            for(int j = 0; j < m; j ++) {
                scanf("%d", &x);
                a[i] += x;
            }
            sum ^= a[i];
        }
        printf("Case %d: ", cas);
        if(sum) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
