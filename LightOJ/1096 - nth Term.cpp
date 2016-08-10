#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 10007;
struct Matrix {

    int m[4][4];
    int r, c;

    Matrix(int _r = 4, int _c = 4):r(_r), c(_c) {
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

    Matrix operator ^ (int b)const {
        Matrix C(r, c);
        Matrix A = *this;
        while(b) {
            if(b & 1) C = C * A;
            b >>= 1;
            A = A * A;
        }
        return C;
    }
};

int main() {
    int T, n, a, b, c;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        Matrix k(4, 4), A(4, 1);

        k.m[0][0] = a;
        k.m[0][1] = 0;
        k.m[0][2] = b;
        k.m[0][3] = c;

        k.m[1][0] = 1;
        k.m[1][1] = 0;
        k.m[1][2] = 0;
        k.m[1][3] = 0;

        k.m[2][0] = 0;
        k.m[2][1] = 1;
        k.m[2][2] = 0;
        k.m[2][3] = 0;

        k.m[3][0] = 0;
        k.m[3][1] = 0;
        k.m[3][2] = 0;
        k.m[3][3] = 1;

        A.m[0][0] = A.m[1][0] = A.m[2][0] = 0;
        A.m[3][0] = 1;

        if(n > 2) {
            k = k ^ (n - 2);
            A = k * A;
        }

        printf("Case %d: %d\n", cas, (n <= 2 ? 0 : A.m[0][0]));
    }
    return 0;
}
