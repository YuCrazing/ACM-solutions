/*
    求解 A^0+A^1+A^2+...+A^n


            | a11 a12 a13 |
    设  A = | a21 a22 a23 |
            | a31 a32 a33 |


             | a11 a12 a13 1 |
    构造 S = | a21 a22 a23 1 | 即可。
             | a31 a32 a33 1 |
             | 0   0   0   1 |
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int C = 26;
const int N = 26;

struct Node {
    int son[C], next;
    bool end;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].end = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char *s) {
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            int &son = no[cur].son[s[i]-'a'];
            if(!son) son = newNode();
            cur = son;
        }
        no[cur].end = true;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int &nex = no[fa].next;
            if(no[nex].end) no[fa].end = true;
            for(int i = 0; i < C; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                    continue;
                }
                no[son].next = no[nex].son[i];
                if(no[fa].end) no[son].end = true;
                q.push(son);
            }
        }
    }
} ac;

struct Matrix {

    int n;
    ull m[N*2][N*2];

    Matrix(int n, int k = 0):n(n) {
        memset(m, 0, sizeof(m));
        if(k) for(int i = 0; i < n; i++) m[i][i] = k;
    }

//    Matrix operator+(const Matrix& b)const {
//        assert(n == b.n);
//        Matrix c(n);
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < n; j++)
//                c.m[i][j] = m[i][j] + b.m[i][j];
//    }

    Matrix operator*(const Matrix& b)const {
        assert(n == b.n);
        Matrix c(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    c.m[i][j] += m[i][k]*b.m[k][j];
        return c;
    }

    Matrix operator^(int b) {
        Matrix c(n, 1), a = (*this);
        while(b) {
            if(b&1) c = c*a;
            a = a*a;
            b >>= 1;
        }
        return c;
    }

    void print() {
        printf("----\n");
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                printf(j== n-1?"%10d\n":"%10d ", m[i][j]);
        printf("----\n");
    }
};

int n, m;
char s[10];
int main() {
    while(scanf("%d%d", &m, &n) != EOF) {
        ac.init();
        for(int i = 0; i < m; i++) {
            scanf("%s", s);
            ac.insert(s);
        }

        ac.bfs();

        int k = ac.tol;

        Matrix a(k+1);
        for(int i = 0; i < k; i++) {
            if(ac.no[i].end) {
                a.m[i][i] = 26;
                continue;
            }
            for(int j = 0; j < C; j++) {
                a.m[i][ac.no[i].son[j]]++;
            }
        }

        for(int i = 0; i < k; i++) if(ac.no[i].end) a.m[i][k] = 1;
        a.m[k][k] = 1;

        a = a^n;

        ull ans = 0;
        for(int i = 0; i < k; i++) {
            if(ac.no[i].end) ans += a.m[0][i];
        }
        ans += a.m[0][k];

        printf("%llu\n", ans);
    }
    return 0;
}
