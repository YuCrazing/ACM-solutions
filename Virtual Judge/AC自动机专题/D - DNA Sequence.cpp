/*
    忘了q.push(son)...
*/

#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 105;
const int CHARS = 4;
const int mod = 100000;
int id[128];

void init() {
    id['A'] = 0;
    id['C'] = 1;
    id['G'] = 2;
    id['T'] = 3;
}

void add(int& a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

struct Node {
    int son[CHARS], next;
    bool bad;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].bad = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char* s) {
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            int &son = no[cur].son[id[s[i]]];
            if(!son) son = newNode();
            cur = son;
        }
        no[cur].bad = true;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < CHARS; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int &nex = no[fa].next;
            if(no[nex].bad) no[fa].bad = true;
            for(int i = 0; i < CHARS; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                    continue;
                }
                no[son].next = no[nex].son[i];
                if(no[fa].bad) no[son].bad = true;
                q.push(son); //!!!
            }
        }
//        for(int i = 0; i < tol; i++) {
//            printf("%3d: %3d %3d\n", i, no[i].next, no[i].bad);
//            for(int j = 0; j < 4; j++){
//                printf("%3d ", no[i].son[j]);
//            }
//            printf("\n\n");
//        }
    }
} ac;

struct Matrix {
    int n, m[N][N];

    Matrix(int _n, int k=0):n(_n) {
        assert(_n < N);
        memset(m, 0, sizeof(m));
        if(k) {
            for(int i = 0; i < n; i++) m[i][i] = k;
        }
    }

    Matrix operator*(const Matrix& b)const {
        assert(n == b.n);
        Matrix c(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    add(c.m[i][j], (long long)(m[i][k])*(long long)(b.m[k][j])%mod);
                }
            }
        }
        return c;
    }

    Matrix operator^(int b) {
        Matrix c(n, 1);
        Matrix a = (*this);
        while(b) {
            if(b&1) c = c*a;
            a = a*a;
            b>>=1;
        }
        return c;
    }

    void print() {
        printf("n = %d\n", n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                printf((j == i-1) ? "%d\n" : "%d ", m[i][j]);
    }
};


int m, n;
char s[15];
int main() {
    init();
    while(scanf("%d%d", &m, &n) != EOF) {

        ac.init();

        for(int i = 0; i < m; i++) {
            scanf("%s", s);
            ac.insert(s);
        }

        ac.bfs();

        Matrix a(ac.tol);
        for(int i = 0; i < ac.tol; i++) {
            if(ac.no[i].bad) continue;
            for(int j = 0; j < CHARS; j++) {
                int son = ac.no[i].son[j];
                if(ac.no[son].bad) continue;
                add(a.m[i][son], 1); //
            }
        }

//    a.print();

        a = a^n;
        int ans = 0;
        for(int i = 0; i < ac.tol; i++) if(!ac.no[i].bad) add(ans, a.m[0][i]);
        printf("%d\n", ans);
    }

    return 0;
}
