/*
    AC自动机

    计算出每个状态之间的初始转移概率矩阵K，每个串的结尾状态只进不出。
    则:
    初始矩阵K的第一行第i列表示从0点走【一步】走到i点的概率（途中不经过任何串的结尾状态）。
    矩阵K^x的第一行第i列表示从0点走【不超过x步】走到i点的概率（途中不经过任何串的结尾状态）。

    可知，K^x的第一行就是我们想要的结果。取一个比较大的x进行矩阵快速幂即可。
    最后到达每个串结尾状态Pi的概率和sum{Pi}可能不是1.0，则取Pi/sum{Pi}即可。
*/

#include<bits/stdc++.h>
using namespace std;

const int N=105;
const int C=6;

struct Matrix {
    int n;
    double m[N][N];

    Matrix(int _n, double _k=0.0):n(_n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                m[i][j]=0;
        if(_k!=0.0) for(int i = 0; i < n; i++) m[i][i]=_k;
    }

    Matrix operator*(const Matrix& b)const {
        assert(n==b.n);
        Matrix c(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    c.m[i][j] += m[i][k]*b.m[k][j];
        return c;
    }

    Matrix operator^(int x) {
        Matrix res(n, 1);
        Matrix a=*this;
        while(x) {
            if(x&1) res = res*a;
            a=a*a;
            x>>=1;
        }
        return res;
    }

    void print() {
        printf("-----\n");
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                printf(j==n-1?"%.3f\n":"%.3f ", m[i][j]);
        printf("-----\n");
    }
};

struct Node {
    int next, son[C], id;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next=no[tol].id=0;
        return tol++;
    }

    void init() {
        tol=0;
        newNode();
    }

    void insert(int *s, int n, int id) {
        int cur=0;
        for(int i = 0; i < n; i++) {
            int &son=no[cur].son[s[i]-1];
            if(!son) son=newNode();
            cur=son;
        }
        no[cur].id=id;
    }

    void build() {
        queue<int> q;
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);

        while(!q.empty()) {
            int fa=q.front();
            q.pop();
            int nex=no[fa].next;
            //if(no[nex].id) no[fa].id=no[nex].id;
            for(int i = 0; i < C; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son=no[nex].son[i];
                    continue;
                }
                no[son].next=no[nex].son[i];
                //if(no[fa].id) no[son].id=no[fa].id;
                q.push(son);
            }
        }
    }

    void debug() {
        for(int i = 0; i < tol; i++) {
            printf("no[%d].next=%d\n", i, no[i].next);
            for(int j = 0; j < C; j++) {
                printf("    son[%d]=%d\n", j, no[i].son[j]);
            }
            printf("-\n");
        }
    }

    Matrix getMat() {
        Matrix a(tol);
        for(int i = 0; i < tol; i++) {
            if(no[i].id) a.m[i][i]=1;
            else {
                int sum=0;
                for(int j = 0; j < C; j++)
                    a.m[i][no[i].son[j]]=1.0/C;
            }
        }
        return a;
    }


} ac;

int T, n, L, a[12];
double ans[12];

int main() {
    scanf("%d", &T);
    while(T--) {
        ac.init();
        scanf("%d%d", &n, &L);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < L; j++) scanf("%d", &a[j]);
            ac.insert(a, L, i+1);
        }
        ac.build();
        Matrix k=ac.getMat();
        k=k^(1<<30);
        double sum=0.0;
        for(int i = 0; i < ac.tol; i++) {
            if(ac.no[i].id) {
                ans[ac.no[i].id]=k.m[0][i];
                sum+=k.m[0][i];
            }
        }
        for(int i = 1; i <= n; i++) printf((i==n?"%f\n":"%f "), ans[i]/sum);
    }
    return 0;
}
