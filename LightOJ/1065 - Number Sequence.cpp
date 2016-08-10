#include <cstdio>
#include <cstring>
using namespace std;

int mod;
struct Matrix {

    int m[2][2];
    int r, c;

    Matrix(int _r = 2, int _c = 2):r(_r),c(_c) {
        memset(m, 0, sizeof(m));
        for(int i = 0; i < r; i ++) m[i][i] = 1;
    }

    Matrix operator * (const Matrix& B)const {
        Matrix C(r, B.c);
        for(int i = 0; i < r; i ++)
            for(int j = 0; j < B.c; j ++) {
                C.m[i][j] = 0;
                for(int k = 0; k < c; k ++)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * B.m[k][j] % mod) % mod;
            }
        return C;
    }
};

Matrix qmod(Matrix A, int b) {
    Matrix C(A.r, A.c);
    while(b) {
        if(b & 1) C = C * A;
        b >>= 1;
        A = A * A;
    }
    return C;
}

int p[5];
void init() {
    p[0] = 1;
    for(int i = 1; i < 5; i ++) p[i] = 10 * p[i - 1];
}

int main() {

    init();

    int T, a, b, n, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d%d%d", &a, &b, &n, &m);
        mod = p[m];
        a %= mod;
        b %= mod;
        Matrix k(2, 2), A(2, 1);
        k.m[0][0] = 1;
        k.m[0][1] = 1;
        k.m[1][0] = 1;
        k.m[1][1] = 0;

        A.m[0][0] = b;
        A.m[1][0] = a;

        k = qmod(k, n);
        A = k * A;
        printf("Case %d: %d\n", cas, (n == 0 ? a : A.m[1][0]));
    }
    return 0;
}
