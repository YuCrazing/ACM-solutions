#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll a[505][505];
int main() {
    int n, x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++) {
            scanf("%I64d", &a[i][j]);
            if(a[i][j] == 0) {
                x = i;
                y = j;
            }
        }

    bool ok = 1;
    ll ans = 1;
    if(n > 1) {

        ll A, B, C, D, sum;
        A = B = C = D = sum = 0;
        for(int i = 0; i < n; i ++) A += a[x][i];

        if(x == 0) {
            for(int i = 0; i < n; i ++) sum += a[n - 1][i];
        } else {
            for(int i = 0; i < n; i ++) sum += a[0][i];
        }

        ans = sum - A;
        if(ans <= 0) ok = 0;
        a[x][y] = ans;

        A = B = C = D = 0;
        for(int i = 0; i < n; i ++) C += a[i][i];
        for(int i = 0; i < n; i ++) D += a[i][n - 1 - i];

        for(int i = 0; i < n; i ++) {
            sum = 0;
            for(int j = 0; j < n; j ++) sum += a[i][j];
            if(C != sum) {
                ok = 0;
                break;
            }
        }

        for(int i = 0; i < n; i ++) {
            sum = 0;
            for(int j = 0; j < n; j ++) sum += a[j][i];
            if(C != sum) {
                ok = 0;
                break;
            }
        }

        if(C != D) ok = 0;
    }

    if(!ok) ans = -1;

    printf("%I64d\n", ans);
    return 0;
}
