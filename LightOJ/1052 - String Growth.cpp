/*
    string = 'a';
    f[i] = string's length after i-th change.

    f[i] = f[i - 1] + f[i - 2]

    |1 1| |f[i + 1]|   |f[i + 2]|
    |1 0| |f[i]    | = |f[i + 1]|

*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Matrix {

    ll mat[2][2];
    int n, m;

    Matrix(int _n = 2, int _m = 2):n(_n),m(_m) {
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(i == j) mat[i][j] = 1;
                else mat[i][j] = 0;
    }

    Matrix operator*(const Matrix& b) {
        if(m != b.n)  m /= 0;
        Matrix C;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < b.m; j ++) {
                C.mat[i][j] = 0;
                for(int k = 0; k < m; k ++)
                    C.mat[i][j] = (mat[i][k] * b.mat[k][j] % mod + C.mat[i][j]) % mod;
            }
        return C;
    }

    void show() {
        printf("==\n");
        printf("(%d %d)\n", n, m);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                printf((j == m - 1) ? "%d\n" : "%d ", mat[i][j]);
        printf("==\n");
    }
};

Matrix qmod(Matrix A, ll b) {
    Matrix res;
    while(b) {
        if(b & 1) res = res * A;
        b >>= 1;
        A = A * A;
    }
    return res;
}

ll f[66];
int ct;
int init() {
    f[1] = f[2] = 1;
    for(ct = 3; ; ct ++) {
        f[ct] = f[ct - 1] + f[ct - 2];
        if(f[ct - 1] + f[ct - 2] > (1LL<<31)) break;
    }
}
int main() {
    init();
    int T, n, m, x, y, k;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d%d%d%d", &n, &x, &m, &y, &k);
        if(n > m) {
            swap(n, m);
            swap(x, y);
        }
        bool no = 0;
        ll x1, x2; // x1: numbers of 'a' in string before start.    x2: numbers of 'b' in string before start.
        if(n >= ct || m >= ct) no = 1;
        else {
            ll D = f[n] * f[m + 1] - f[n + 1] * f[m];
            x1 = x * f[m + 1] - y * f[n + 1];
            x2 = y * f[n] - x * f[m];
            if((x1 % D) || (x2 % D)) no = 1;
            x1 = x1 / D;
            x2 = x2 / D;
            if(x1 < 0 || x2 < 0) no = 1;
        }

        printf("Case %d: ", cas);
        if(no) {
            printf("Impossible\n");
            continue;
        }

        Matrix K, F(2, 1);
        K.mat[0][0] = K.mat[0][1] = K.mat[1][0] = 1;//[1, 1; 1, 0]
        K.mat[1][1] = 0;

        F.mat[0][0] = F.mat[1][0] = 1; //[f[2]; f[1]]

        Matrix res = qmod(K, k - 1) * F;
//        res.show();
        printf("%lld\n", (res.mat[0][0] * x2 % mod + res.mat[1][0] * x1 % mod) % mod);
    }
    return 0;
}
