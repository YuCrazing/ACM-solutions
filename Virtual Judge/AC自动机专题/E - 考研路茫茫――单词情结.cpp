/*
    S(n) = E + A^1 + A^2 + ... + A^n

    |  A    E  |    |S(n-1) S(n)|   |S(n) S(n+1)|
    |          |  * |           | = |           |
    |  0    E  |    |E      E   |   |E    E     |

    对于end=true的节点，进去就不要出来了。
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
        Matrix a(2*k), a0(2*k, 1);

        for(int i = 0; i < k; i++) a.m[i][i+k] = 1;//
        for(int i = 0; i < k; i++) a.m[i+k][i+k] = 1;//
        for(int i = 0; i < k; i++) {
            if(ac.no[i].end) {
                a.m[i][i] = 26; // 到达end节点就不会出来了
                continue;
            }
            for(int j = 0; j < C; j++) {
                a.m[i][ac.no[i].son[j]]++;
            }
        }
        for(int i = 0; i < k; i++) a0.m[i+k][i] = 1;//
        for(int i = 0; i < k; i++) a0.m[i][i+k] = 1;//
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
                a0.m[i][k+j] += a.m[i][j];

//        a.print();
        a = (a^n)*a0;
//        a.print();
        ull ans = 0;
        for(int i = 0; i < k; i++) {
            if(ac.no[i].end) ans += a.m[0][i];
        }
        printf("%llu\n", ans);
    }
    return 0;
}
