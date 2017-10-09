#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
typedef long long ll;

const int N=1e5+5;
ll a[N], suf[N];
int sid[N];
vector<int> pa, pb;
vector<ll> pc;
int n;

void add(int a, int b, ll c) {
    if(a>b)swap(a, b);
    pa.push_back(a);
    pb.push_back(b);
    pc.push_back(c);
}

void check(int id) {
    for(int i = 1; i <= n; i++) {
        if(i==id) continue;
        ll mi=min(a[i], a[id]);
        if(mi==0) continue;
        a[i]-=mi;
        a[id]-=mi;
        add(id, i, mi);
    }
}
int main() {
    //freopen("magic.in", "r", stdin);
    //freopen("magic.out", "w", stdout);

    scanf("%d", &n);
    ll sum=0, mx=-1;
    int mxid=-1;
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        sum+=a[i];
    }

    for(int i = 1; i <= n; i++) {
        if(mx<a[i]) {
            mx=a[i];
            mxid=i;
        }
    }

    ll dif=mx-(sum-mx);
    if(dif>=0) {
        mx-=dif;
        sum-=dif;
        check(mxid);
    } else {
//        if(sum&1) {
//            a[n]--;
//            sum--;
//        }
        suf[n+1]=0;
        for(int i = n; i > 0; i--) {
            if(a[i] > suf[i+1]) {
                suf[i]=a[i];
                sid[i]=i;
            } else {
                suf[i]=suf[i+1];
                sid[i]=sid[i+1];
            }
        }
        int i=1,j=2;
        while(sum) {
            ll mxp=(sum-2*suf[j+1])/2;
            if(mxp<1) {
                j++;
                while(j)j++;
            }
            ll mi=min(a[i], a[j]);
            if(mi < mxp) {
                a[i]-=mi;
                a[j]-=mi;
                sum-=2*mi;
                add(i, j, mi);
                if(a[i]==0) {
                    i=j;
                    while(a[i]==0&&i<n) i++;
                    if(i==n) break;
                    j=i+1;
                    while(a[j]==0) j++;
                } else {
                    while(a[j]==0&&j<=n) j++;
                    if(j>n) break;
                }
            } else {
                sum-=2*mxp;
                a[i]-=mxp;
                a[j]-=mxp;
                add(i, j, mxp);
                if(sum==0) break;
                check(sid[j+1]);
                break;
            }
        }
    }
    printf("%d\n", pa.size());
    for(int i = 0; i < pa.size(); i++) {
        printf("%d %d %I64d\n", pa[i], pb[i], pc[i]);
    }

    return 0;
}
