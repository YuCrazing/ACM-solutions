#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;

struct Matrix {
    ull m[4][4];
    int r, c;

    Matrix(int _r = 4, int _c = 4):r(_r),c(_c) {
        memset(m, 0, sizeof(m));
        for(int i = 0; i < r; i ++) m[i][i] = 1;
    }

    Matrix operator *(const Matrix& B)const {
        Matrix C(r, B.c);
        for(int i = 0; i < r; i ++)
            for(int j = 0; j < B.c; j ++) {
                C.m[i][j] = 0;
                for(int k = 0; k < c; k ++) C.m[i][j] += m[i][k] * B.m[k][j];
            }
        return C;
    }

};

Matrix qmod(Matrix A, ull b) {
    Matrix C(A.r, A.c);
    while(b) {
        if(b & 1) C = C * A;
        b >>= 1;
        A = A * A;
    }
    return C;
}
int main() {
    int T;
    ull p, q, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%llu%llu%llu", &p, &q, &n);
        Matrix k(4, 4), A(2, 1);
        k.m[0][0] = p;
        k.m[0][1] = -q;
        k.m[1][0] = 1;
        k.m[1][1] = 0;

        A.m[0][0] = p;
        A.m[1][0] = 2;

        k = qmod(k, n);
        A = k * A;
        printf("Case %d: %llu\n", cas, (n == 0 ? 2 : A.m[1][0]));
    }
    return 0;
}
