
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N=5e5+4;
const int MM=1e6+5;

struct P{
    int v, h, i;
};
P p[N];

int n, T, A, B, C, D, E, F, M;
ll c[MM], cnt[N][4];
ll num[MM];

int low(int x){
    return x&(-x);
}

void add(int a){
    for(int i = a; i <= MM; i += low(i)) c[i]++;
}

ll ask(int a){
//    assert(a>=-1);
//    if(a==-1) return 0;
    ll r=0;
    for(int i = a; i > 0; i -= low(i)) r += c[i];
    return r;
}

void init(){
    for(int i = 0; i < MM; i++) c[i]=0;
    for(int i = 0; i < MM; i++) num[i]=0;
}

bool cmp0(const P &a, const P &b){
    if(a.v==b.v) return a.h<b.h;
    return a.v < b.v;
}

bool cmp1(const P &a, const P &b){
    if(a.v==b.v) return a.h>b.h;
    return a.v < b.v;
}

bool cmp2(const P &a, const P &b){
    if(a.v==b.v) return a.h<b.h;
    return a.v > b.v;
}

bool cmp3(const P &a, const P &b){
    if(a.v==b.v) return a.h>b.h;
    return a.v > b.v;
}

ll c3(ll x){
    return x*(x-1)*(x-2)/6;
}

int main(){
    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large-practice.out", "w", stdout);
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        //printf("%d %d\n", ca, T);
        scanf("%d%d%d%d%d%d%d%d%d%d", &n, &p[0].v, &p[0].h, &A, &B, &C, &D, &E, &F, &M);
        for(int i = 1; i < n; i++){
            p[i].v=(A*(ll)p[i-1].v+B*(ll)p[i-1].h+(ll)C)%M;
            p[i].h=(D*(ll)p[i-1].v+E*(ll)p[i-1].h+(ll)F)%M;
            p[i].i=i;
            //printf("(%d %d)\n", p[i].v, p[i].h);
        }
        p[0].i=0;
        for(int i = 0; i < n; i++) {
            p[i].v++;
            p[i].h++;
            for(int j = 0; j < 4; ++j) cnt[i][j]=0;
        }

        //left-down
        init();
        sort(p, p+n, cmp0);
        for(int i = 0; i < n; i++){
            //printf("(%d %d)\n", p[i].v, p[i].h);
            cnt[p[i].i][0]=ask(p[i].h-1)-num[p[i].v];
            //printf("%d %d %d\n", p[i].i, (int)ask(p[i].h-1), (int)num[p[i].v]);
            add(p[i].h);
            num[p[i].v]++;
        }

        //left-up
        init();
        sort(p, p+n, cmp1);
        for(int i = 0; i < n; i++){
            cnt[p[i].i][1]=(i-ask(p[i].h))-num[p[i].v];
            add(p[i].h);
            num[p[i].v]++;
        }

        //right-down
        init();
        sort(p, p+n, cmp2);
        for(int i = 0; i < n; i++){
            cnt[p[i].i][2]=ask(p[i].h-1)-num[p[i].v];
            //printf("(%d %d)\n", p[i].v, p[i].h);
            //printf("%d %d %d\n", p[i].i, (int)ask(p[i].h), (int)num[p[i].v]);
            add(p[i].h);
            num[p[i].v]++;
        }

        //right-up
        init();
        sort(p, p+n, cmp3);
        for(int i = 0; i < n; i++){
            cnt[p[i].i][3]=(i-ask(p[i].h))-num[p[i].v];
            add(p[i].h);
            num[p[i].v]++;
        }

        ll ans=c3(n);
        for(int i = 0; i < n; i++){
            //printf("%d %d %d %d %d\n", i, cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][3]);
            ans -= (cnt[i][0]*cnt[i][3]);
            ans -= (cnt[i][1]*cnt[i][2]);
        }
        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}
