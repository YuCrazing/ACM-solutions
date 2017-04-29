#include<cstdio>
#include<cstring>
#include<queue>
#include<cassert>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

const int N = 55;
const int CHARS = 26;

struct Matrix {
    int n;
    uint m[N][N];

    Matrix(int _n, ll x = 0):n(_n) {
        assert(n <= N);
        memset(m, 0, sizeof(m));
        if(x) {
            for(int i = 0; i < n; i++) m[i][i] = x;
        }
    }

    Matrix operator*(const Matrix& b) const {
        Matrix c(n);
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    c.m[i][j] =c.m[i][j] + m[i][k] * b.m[k][j];
        return c;
    }

    Matrix operator^(int b) const {
        Matrix res(n, 1);
        Matrix a = (*this);
        while(b) {
            if(b&1) res = res * a;
            b >>= 1;
            a = a * a;
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
    return x - 'a';
}

struct Node {
    int son[CHARS];
    int next;
    bool end;
};

struct AC {
    Node node[N];
    int tol;

    int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].end = 0;
        assert(tol < N);
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
        for(int i = 0; i < CHARS; i++) if(node[0].son[i]) q.push(node[0].son[i]);

        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            for(int i = 0; i < CHARS; i++) {
                int& son = node[fa].son[i];
                int next = node[fa].next;
                if(!son) {
                    son = node[next].son[i];
                    continue;
                }
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

Matrix genMatrix(char *s) {
    ac.bfs();
    Matrix mat(ac.tol);
    for(; *s; s++) { // !
        int id = getid(*s);
        for(int i = 0; i < ac.tol; i++) {
            if(ac.node[i].end) continue;
            int son = ac.node[i].son[id];
            if(ac.node[son].end) continue;
            mat.m[i][son]++;
        }
    }
    return mat;
}

uint gao(char*s, int n) {
    Matrix k = genMatrix(s);
    //ac.debug();
    //k.print();
    Matrix res = k ^ n;
    uint sum = 0;
    for(int i = 0; i < res.n; i++)
        sum = sum + res.m[0][i];
    return sum;
}


char s[55], chars[33];
int main() {
    int n, T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%s%s", &n, chars, s);

        ac.init();
        ac.insert(s);

        printf("Case %d: %u\n", ca, gao(chars, n)); //
    }
    return 0;
}

