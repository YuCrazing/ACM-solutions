#include<cstdio>
#include<cstring>
#include<queue>
#include<cassert>

using namespace std;

typedef long long ll;

const ll mod = 100000;
const int N = 101;

struct Matrix {
    int n;
    ll m[N][N];

    Matrix(int _n, ll x = 0):n(_n) {
        //assert(n <= N);
        memset(m, 0, sizeof(m));
        if(x) {
            for(int i = 0; i < n; i++) m[i][i] = x;
        }
    }

    Matrix operator*(const Matrix& b) const {
        //assert(n == b.n);
        Matrix c(n);
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++) {
                    c.m[i][j] = m[i][k] * b.m[k][j] + c.m[i][j];
                    if(c.m[i][j] > mod) c.m[i][j] %= mod;
                }
        return c;
    }

    Matrix operator^(int b) const {
        Matrix res(n, 1);
        Matrix a = (*this);
        while(b) {
            if(b&1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    void print() {
        printf("--- %d\n", n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                printf((j == n - 1) ? "%d\n" : "%d ", (int)m[i][j]);
        printf("---\n");
    }
};

inline int getid(char& x) {
    if(x == 'A') return 0;
    if(x == 'C') return 1;
    if(x == 'T') return 2;
    if(x == 'G') return 3;
    //assert(0);
}

struct Node {
    int son[4];
    int next;
    bool end;
};

struct AC {
    Node node[N];
    int tol;

    int newNode() {
        //assert(tol < N);
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].end = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char* s) {
        int cur = 0;
        for(; *s; s++) {
            int& son = node[cur].son[getid(*s)];
            if(!son) son = newNode();
            cur = son;
        }
        node[cur].end = 1;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < 4; i++) if(node[0].son[i]) q.push(node[0].son[i]);

        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int& son = node[fa].son[i];
                int next = node[fa].next;
                if(!son) {
                    son = node[next].son[i];
                    continue;
                }
                if(node[next].end) node[fa].end = 1;
                //if(node[fa].end) node[son].end = 1;
                node[son].next = node[next].son[i];
                q.push(son);
            }
        }
    }

    void debug() {
        printf("--\n");
        printf("tol = %d\n", tol);
        for(int i = 0; i < tol; i++) {
            printf("...\n");
            printf("node[%d].next = %d\n", i, node[i].next);
            for(int j = 0; j < 4; j ++) printf("node[%d].son[%d] = %d\n", i, j, node[i].son[j]);
            printf("...\n");
        }
        printf("--\n");
    }
} ac;

Matrix genMatrix() {
    ac.bfs();
    Matrix mat(ac.tol);
    for(int i = 0; i < ac.tol; i++) {
        if(ac.node[i].end) continue;
        for(int j = 0; j < 4; j++) {
            int son = ac.node[i].son[j];
            if(ac.node[son].end) continue;
            mat.m[i][son]++;
        }
    }
    //mat.print();
    return mat;
}
int gao(int n) {
    Matrix k = genMatrix();
    Matrix res = k ^ n;
    ll sum = 0;
    for(int i = 0; i < ac.tol; i++) {
        sum = (sum + res.m[0][i]) % mod;
    }
    return (int)sum;
}

char s[13];

int main() {
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        ac.init();
        for(int i = 0; i < m; i++) {
            scanf("%s", s);
            ac.insert(s);
        }
        printf("%d\n", gao(n));
    }
    return 0;
}
/*
4 3
AT
AC
AG
AA

4 1
A
C
T
G

3 1
A
C
T
2 2000000000
A
C

0 5

2 3
A
ATG

2 4
AC
ACTG

2 5
TG
ACTGT

*/
