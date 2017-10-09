/*
    化简为两种操作：
    1.将区间中所有数替换为a；
    2.将区间中所有数乘上a然后加上b


    注意：
        替换操作的默认值不能是0，因为取膜后有可能出现替换为0的情况 (WA)
        往孩子传标记的时候，孩子的sum值也要同时更新
*/


#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=1e5+5;
const int mod=10007;

void add(int &a, int b) {
    a+=b;
    if(a>=mod) a%=mod;
}

void mul(int &a, int b) {
    if(a>=mod) a%=mod;
    if(b>=mod) b%=mod;
    a*=b;
    if(a>=mod) a%=mod;
}

void add(int &a, int b, int c) {
    mul(b, c);
    add(a, b);
}

void mul_add(int &a, int b, int c) {
    mul(a, b);
    add(a, c);
}

struct Node {
    int l, r, val[3], sum[3];
};

struct Tree {

    Node no[N<<2];

    // x->a
    void replace(int rt, int a) {
        no[rt].val[0]=a;
        no[rt].val[1]=1;
        no[rt].val[2]=0;

        int t=no[rt].r-no[rt].l+1;
        mul(t, a);
        no[rt].sum[0]=t;
        mul(t, a);
        no[rt].sum[1]=t;
        mul(t, a);
        no[rt].sum[2]=t;
    }

    // x*a+b
    void change(int rt, int a, int b) {
        if(no[rt].val[0]!=-1) {
            mul_add(no[rt].val[0], a, b);
        } else {
            mul(no[rt].val[1], a);
            mul_add(no[rt].val[2], a, b);
        }

        int s0=no[rt].sum[0];
        int s1=no[rt].sum[1];

        //
        int t=no[rt].r-no[rt].l+1;
        mul(t, b);
        mul_add(no[rt].sum[0], a, t);

        //
        mul(no[rt].sum[1], a);
        mul(no[rt].sum[1], a);

        int ab2Sum0=s0;
        mul(ab2Sum0, 2);
        mul(ab2Sum0, a);
        mul(ab2Sum0, b);
        add(no[rt].sum[1], ab2Sum0);
        mul(t, b);
        add(no[rt].sum[1], t);

        //
        mul(no[rt].sum[2], a);
        mul(no[rt].sum[2], a);
        mul(no[rt].sum[2], a);

        int aab3Sum1=s1;
        mul(aab3Sum1, 3);
        mul(aab3Sum1, a);
        mul(aab3Sum1, a);
        mul(aab3Sum1, b);
        add(no[rt].sum[2], aab3Sum1);

        int abb3Sum0=s0;
        mul(abb3Sum0, 3);
        mul(abb3Sum0, a);
        mul(abb3Sum0, b);
        mul(abb3Sum0, b);
        add(no[rt].sum[2], abb3Sum0);

        mul(t, b);
        add(no[rt].sum[2], t);

    }

    void pushUp(int rt) {
        no[rt].sum[0]=no[lson].sum[0]+no[rson].sum[0];
        no[rt].sum[1]=no[lson].sum[1]+no[rson].sum[1];
        no[rt].sum[2]=no[lson].sum[2]+no[rson].sum[2];
    }

    void pushDown(int rt) {
        if(no[rt].val[0]!=-1) {
            replace(lson, no[rt].val[0]);
            replace(rson, no[rt].val[0]);
        } else if(no[rt].val[1]!=1 || no[rt].val[2]) {
            change(lson, no[rt].val[1], no[rt].val[2]);
            change(rson, no[rt].val[1], no[rt].val[2]);
        }
        no[rt].val[0]=-1;
        no[rt].val[1]=1;
        no[rt].val[2]=0;
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        no[rt].val[0]=-1;
        no[rt].val[1]=1;
        no[rt].val[2]=0;
        if(l==r) {
            no[rt].sum[0]=no[rt].sum[1]=no[rt].sum[2]=0;
            return ;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
        pushUp(rt);
    }

    void upd(int a, int b, int c, int type, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            if(type==1) replace(rt, c);
            else if(type==2) change(rt, 1, c);
            else change(rt, c, 0);
            return ;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) upd(a, b, c, type, lson);
        if(b>mid) upd(a, b, c, type, rson);
        pushUp(rt);
    }

    int ask(int a, int b, int ch, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            return no[rt].sum[ch-1];
        }
        pushDown(rt);
        int mid=(l+r)>>1, ans=0;
        if(a<=mid) add(ans, ask(a, b, ch, lson));
        if(b>mid) add(ans, ask(a, b, ch, rson));
        return ans;
    }

    void debug() {
        int n=no[1].r;
        for(int i = 1; i <= n; i++) printf("%d: [%d %d %d]\n", i, ask(i, i, 1, 1), ask(i, i, 2, 1), ask(i, i, 3, 1));
    }
} tree;

// debug
struct Brute {
    int num[N], n;
    void init(int _n) {
        n=_n;
        for(int i = 1; i <= n; i++) num[i]=0;
    }

    void upd(int a, int b, int c, int type) {
        if(type==1) {
            for(int i = a; i <= b; i++) num[i]=c;
        } else if(type==2) {
            for(int i = a; i <= b; i++) add(num[i], c);
        } else for(int i = a; i <= b; i++) mul(num[i], c);
    }

    int ask(int a, int b, int p) {
        int ans=0;
        for(int i = a; i <= b; i++) {
            int t=1;
            for(int j=0; j<p; j++)mul(t, num[i]);
            add(ans, t);
        }
        return ans;
    }

    void debug() {
        for(int i = 1; i <= n; i++) printf("%d: [%d %d %d]\n",i, num[i],  num[i]*num[i]%mod, num[i]*num[i]%mod*num[i]%mod);
    }
} brute;


int n, m, a, b, c, op;
int main() {
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    while(scanf("%d%d", &n, &m)!=EOF) {
        if(!n&&!m) break;
        tree.init(1, n, 1);
        //brute.init(n);
        while(m--) {
            scanf("%d%d%d%d", &op, &a, &b, &c);
            switch(op) {
            case 1:
                tree.upd(a, b, c, 2, 1);
                //brute.upd(a, b, c, 2);
                break;
            case 2:
                tree.upd(a, b, c, 3, 1);
                //brute.upd(a, b, c, 3);
                break;
            case 3:
                tree.upd(a, b, c, 1, 1);
                //brute.upd(a, b, c, 1);
                break;
            case 4:
                printf("%d\n", tree.ask(a, b, c, 1));
                //printf("%d\n", brute.ask(a, b, c));
                break;
            }
            //tree.debug();
            //brute.debug();
        }
    }
    return 0;
}
/*
10 100
1 1 10 1
1 1 10 1
1 1 5 1
3 1 4 1

*/
