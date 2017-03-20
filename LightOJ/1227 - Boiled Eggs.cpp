#include <cstdio>
#include <algorithm>
using namespace std;

int a[33];
int main() {
    int T, P, Q, n;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d%d", &n, &P, &Q);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        int sum = 0, i;
        for(i = 0; i < min(P, n); i++) {    //min(P, n)
            if(sum + a[i] > Q) {
                i--;
                break;
            }
            sum += a[i];
        }
        if(i >= P) i--;
        if(i >= n) i--; //important.
        printf("Case %d: %d\n", ca, i + 1);
    }
    return 0;
}
