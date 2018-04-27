
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N=103;

int c[N], d[N], b[N], len, n, k, T;
ll p;

int low(int x){
    return x&(-x);
}

void add(int a, int b){
    for(int i = a; i <= n; i += low(i)) c[i]+=b;
}

int ask(int a){
    int r=0;
    for(int i = a; i > 0; i -= low(i)) r += c[i];
    return r;
}

vector<int> v;
void init(){
    memset(c, 0, sizeof(c));
    memset(d, -1, sizeof(d));
    len=0;
    v.clear();
}

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        scanf("%d%d%lld", &n, &k, &p);
        init();
        int l, r, ch;
        for(int i = 0; i < k; i++){
            scanf("%d%d%d", &l, &r, &ch);
            add(l, 1);
            add(r+1, -1);
            d[l]=ch;
        }
        for(int i = n; i >=1; i--){
            //printf("%d %d\n", i, ask(i));
            if(ask(i)==0) v.push_back(i);
        }
        --p;
        while(p){
            b[len++]=(p&1);
            p >>= 1;
        }
        //reverse(b, b+len);
        for(int i = 0; i < len; ++i){
            d[v[i]]=b[i];
            //printf("%d %d\n", v[i], b[i]);
        }
        printf("Case #%d: ", ca);
        for(int i = 1; i <= n; ++i) printf("%d", (d[i]==-1?0:d[i]));
        puts("");
    }
    return 0;
}
