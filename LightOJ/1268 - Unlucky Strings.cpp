#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ull;

struct Matrix {

    ull m[55][55];
    int n;

    Matrix(int _n = 0, int x = 0):n(_n) {
        memset(m, 0, sizeof(m));
        if(x) {
            for(int i = 0; i < n; i++) m[i][i] = x;
        }
    }

    Matrix operator*(const Matrix b) {
        Matrix c(n, 0);
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    c.m[i][j] += m[i][k] * b.m[k][j];
        return c;
    }

    Matrix operator^(int b) {
        Matrix res(n, 1), a(*this); //
        while(b) {
            if(b&1) res = res * a;
            b >>= 1;
            a = a * a;
        }
        return res;
    }

    void print() {
        cout << "---" << endl;
        cout << n << "*" << n << ":" << endl;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cout << m[i][j] << ((j == n - 1) ? "\n" : " ");
        cout << "---" << endl;
    }
};

Matrix mat;
int T, n, pi[55];
string ban, chars;

void kmp() {
    int l = ban.size(), j = 0;
    pi[0] = pi[1] = 0;
    for(int i = 1; i < l; i++) {
        while(j > 0 && ban[j] != ban[i]) j = pi[j];
        if(ban[j] == ban[i]) j++;
        pi[i + 1] = j;
    }
}

void genMatrix() {
    int lb = ban.size(), lc = chars.size();
    mat = Matrix(lb, 0); //
    for(int i = 0; i < lb; i++) {
        for(int j = 0; j < lc; j++) {
            int l = i;
            while(l && ban[l] != chars[j]) l = pi[l];
            if(ban[l] == chars[j]) l ++;
            mat.m[i][l]++;
        }
    }
}

ull calc() {
    Matrix res = mat^n;
//    mat.print();
//    res.print();
    ull ans = 0;
    for(int i = 0; i < mat.n; i++) ans+= res.m[0][i];
    return ans;
}

int main() {

    ios::sync_with_stdio(false);

    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        cin >> n;
        cin >> chars >> ban;

        kmp();
        genMatrix();

        cout << "Case " << ca << ": " << calc() << endl;
    }
    return 0;
}
