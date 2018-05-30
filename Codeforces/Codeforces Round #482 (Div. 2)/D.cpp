/*
    想错了一个地方：该往右走的时候，不能贪心地往右走，有可能右边的数都是大于 s-x 的，
    应该记一个子树最小值，确保右边有小于等于 s-x 的数。
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;


const int N=1e5+3;
const int MAXN=3e7;


struct Node {
    int son[2], mn;
} no[MAXN];

int tol;

struct Tree {

    int rt;

    int newNode() {
        assert(tol<MAXN);
        no[tol].son[0]=no[tol].son[1]=-1;
        no[tol].mn = 1e5 + 5;
        return tol++;
    }

    void init() {
        rt = newNode();
    }

    void insert(int n) {
        int cur=rt; //!!!!!
        for(int i = 16; i >= 0; --i) {
            int &son = no[cur].son[(bool)(n&(1<<i))];
            if(son==-1) son=newNode();
            cur=son;
            no[cur].mn=min(no[cur].mn, n);
        }
    }

    int search(int x, int s) {
        int cur=rt, v=0, son; // cur=rt 不是 cur=0
        bool ban=true;
        for(int i = 16; i >= 0; --i) {
            int go=!(x&(1<<i));
            int only=(bool)(s&(1<<i));
            if(ban && only==0) {
                go=0;
                son = no[cur].son[go];
            } else if(ban && only==1) {
                son=no[cur].son[go];
                if(son==-1 || no[son].mn > s) {
                    go=!go;
                    son=no[cur].son[go];
                }
                if(go==0) ban=false;
            } else {
                son=no[cur].son[go];
                if(son==-1) {
                    go=!go;
                    son=no[cur].son[go];
                }
            }
            cur=son;
            if(cur==-1 || no[cur].mn > s) return -1;
            v <<= 1;
            if(go) ++v;
        }
        return v;
    }
};

Tree t[N];
vector<int> v[N];

int main() {

    for(int i = 1; i < N; ++i) {
        t[i].init();
        for(int j = 1; j*i < N; ++j) {
            v[i*j].push_back(i);
        }
    }

    int x, k, s, op, q;
    scanf("%d", &q);
    while(q--) {
        scanf("%d",&op);
        if(op==1) {
            scanf("%d", &x);
            for(int i = 0; i < v[x].size(); ++i) t[v[x][i]].insert(x);
        } else {
            scanf("%d%d%d", &x, &k, &s);
            int ans=-1;
            int tans=-1;
            s=s-x;
            if(x%k==0 && s>0) {
                ans = t[k].search(x, s);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}

/*

100
1 15771
1 2019
2 7251 1 18353


*/
