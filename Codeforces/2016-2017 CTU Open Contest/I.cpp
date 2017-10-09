#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=1e5+5;

struct Event {
    int t, val;

} a[N];

struct Node {
    int mx, mi, sum, l, r;
};

struct Tree {

    Node no[N<<2];

    void pushUp(int rt) {
        no[rt].sum=no[lson].sum+no[rson].sum;
        no[rt].mx=max(no[lson].mx, no[rson].mx);
        no[rt].mi=min(no[lson].mi, no[rson].mi);
    }

    void build(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        if(l==r) {
            no[rt].mx=no[rt].mi=no[rt].sum=a[l].val;
            return;
        }
        int mid=(l+r)>>1;
        build(l, mid, lson);
        build(mid+1, r, rson);
        pushUp(rt);
    }

    int ask(int a, int b, int ch, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a <= l && b >= r) {
            if(ch==0) return no[rt].sum;
            if(ch==1) return no[rt].mx;
            if(ch==2) return no[rt].mi;
        }
        int mid=(l+r)>>1;
        if(ch==0) {
            int ans=0;
            if(a<=mid) ans+=ask(a, b, ch, lson);
            if(b>mid) ans+=ask(a, b, ch, rson);
            return ans;
        } else if(ch==1) {
            int ans=0;
            if(a<=mid) ans=max(ans, ask(a, b, ch, lson));
            if(b>mid) ans=max(ans, ask(a, b, ch, rson));
            return ans;
        } else {
            int ans=2e9;;
            if(a<=mid) ans=min(ans, ask(a, b, ch, lson));
            if(b>mid) ans=min(ans, ask(a, b, ch, rson));
            return ans;
        }
    }
} tree;

int n, c, ti, b[N];
char op1[10], op2[10];
int main() {
    while(scanf("%d", &n)!=EOF) {
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].t, &a[i].val);
            //b[i]=a[i].val;
        }
//        sort(b+1, b+n+1);
//        int m=unique(b+1, b+n+1)-b-1;
//        for(int i = 1; i <= n; i++) {
//            a[i].id=lower_bound(b+1, b+m+1, a[i].t)-b;
//        }
        tree.build(1, n, 1);
        scanf("%d", &c);
        for(int k=0; k<c; k++) {
            scanf("%s%s%d", op1, op2, &ti);
            int ch;
            if(op2[2]=='n') ch=2;
            else if(op2[2]=='x') ch=1;
            else ch=0;
            int j=1, ans=0;
            for(int i = 1; i <= n; i++) {
                while(j!=i&&a[i].t-a[j].t>ti)j++;
                if(j==i) {
                    //if(op1[0]=='g') ans++;
                } else {
                    if(ch==0) {
                        int sum=tree.ask(j, i-1, ch, 1);
                        //printf("[%d %d] %d %d %d %d\n",j,i-1, sum,a[i].val,a[i].val*(i-j), sum/(i-j));
                        int t=a[i].val*(i-j);
                        if(op1[0]=='g' && t>sum) ans++;
                        else if(op1[0]=='l' && t<sum) ans++;
                    } else if(ch==1) {
                        int mx=tree.ask(j, i-1, ch, 1);
                        if(op1[0]=='g' && a[i].val>mx) ans++;
                        else if(op1[0]=='l' && a[i].val<mx) ans++;
                    } else {
                        int mi=tree.ask(j, i-1, ch, 1);
                        if(op1[0]=='g' && a[i].val>mi) ans++;
                        else if(op1[0]=='l' && a[i].val<mi) ans++;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
