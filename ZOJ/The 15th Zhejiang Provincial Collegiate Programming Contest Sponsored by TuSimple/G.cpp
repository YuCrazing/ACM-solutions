/*
    注意 unsigned long long 与 long long 混合运算时的类型转换，
    long long 会被转换为 unsigned long long 。
    signed 与 unsigned 操作数混合运算时，类型转换比较复杂。
    
    
    这道题目卡掉了常用的单 hash 方法（包括 unsigned long long 自然溢出 和 随机取模），使用双 hash 才能通过。 
	卡单 hash 的方法见 BZOJ 3097, 3098, 3309 
*/

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;

const ll P=193LL;
const ll MOD1=1610612741LL;
const ll MOD2=12582917LL;
const int N=100005;
char s[N], t[N];
ll x, y;
pair<ll, ll> p[N], subHash[N], preHash[N], sufHash[N], a[N], aa[N];
vector<int> v[N];
int main() {

    for(int i = 0; i < N; ++i) {
        p[i].fi=(i?p[i-1].fi*P%MOD1:1);
        p[i].se=(i?p[i-1].se*P%MOD2:1);
    }

    int T, q, n, m;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {

        scanf("%d%d%d", &n, &m, &q);
        scanf("%s%s", s, t);

        for(int i = 0; i < m; ++i) v[i].clear(); //!!!!

        ll sum1=0, sum2=0;
        for(int i = 0; i < m; ++i) {
            sum1*=P;
            sum1%=MOD1;
            sum1+=s[i];
            sum1%=MOD1;

            sum2*=P;
            sum2%=MOD2;
            sum2+=s[i];
            sum2%=MOD2;
        }
        subHash[0]= {sum1, sum2};
        for(int i = 1; i+m-1 < n; ++i) {
            sum1-=s[i-1]*p[m-1].fi%MOD1;
            sum1%=MOD1;
            if(sum1<0) sum1+=MOD1;
            sum1*=P;
            sum1%=MOD1;
            sum1+=s[i+m-1];
            sum1%=MOD1;

            sum2-=s[i-1]*p[m-1].se%MOD2;
            sum2%=MOD2;
            if(sum2<0) sum2+=MOD2;
            sum2*=P;
            sum2%=MOD2;
            sum2+=s[i+m-1];
            sum2%=MOD2;
            subHash[i]= {sum1, sum2};
        }

        sum1=sum2=0;
        for(int i = 0; i < m; ++i) {
            sum1*=P;
            sum1%=MOD1;
            sum1+=t[i];
            sum1%=MOD1;

            sum2*=P;
            sum2%=MOD2;
            sum2+=t[i];
            sum2%=MOD2;
        }
        sufHash[0]= {sum1, sum2};
        for(int i = 0; i < m; ++i) {
            sum1-=t[i]*p[m-1].fi%MOD1;
            if(sum1<0) sum1+=MOD1;
            sum1*=P;
            sum1%=MOD1;

            sum2-=t[i]*p[m-1].se%MOD2;
            if(sum2<0) sum2+=MOD2;
            sum2*=P;
            sum2%=MOD2;
            sufHash[i+1]= {sum1, sum2};
        }
        assert(sufHash[m].fi==0 && sufHash[m].se==0);
        sum1=sum2=0;
        for(int i = 0; i < m; ++i) {
            sum1*=P;
            sum1%=MOD1;
            sum1+=t[i];
            sum1%=MOD1;

            sum2*=P;
            sum2%=MOD2;
            sum2+=t[i];
            sum2%=MOD2;
            preHash[i]= {sum1, sum2};
        }
        for(int i = 0; i < m; ++i) {
            a[i]= {(sufHash[i+1].fi+preHash[i].fi)%MOD1, (sufHash[i+1].se+preHash[i].se)%MOD2};
            aa[i]=a[i];
        }
        sort(aa, aa+m);
        int l=unique(aa, aa+m)-aa;
        for(int i = 0; i < m; ++i) {
            int id=lower_bound(aa, aa+l, a[i])-aa;
            v[id].push_back(i+1);
        }
        for(int i = 0; i < q; ++i) {
            scanf("%llu%llu", &x, &y);
            --x;
            int id = lower_bound(aa, aa+l, subHash[x]) - aa;
            ll ans=0;
            if(id!=l && aa[id]==subHash[x]) {
                assert(v[id].size());
                int md=y%m;
                vector<int>::iterator it = upper_bound(v[id].begin(), v[id].end(), md);
                if(it==v[id].end()) {
                    ans=v[id].size()*(y/m+1);
                } else {
                    int num=it-v[id].begin();
                    ans=v[id].size()*(y/m)+num;
                }
            }
            printf("%llu\n", ans);
        }
    }
}

/*



10
10 7 4
aaaaaaaaaa
aaaaaaa
1 1
2 1
3 1
4 1
10 7 16
aaaaaaaaaa
aaaaaaa
4 1
4 2
4 3
4 4
4 5
4 6
4 7
4 8
4 9
4 10
4 11
4 12
4 13
4 14
4 15
4 16
5 4 6
aabcd
bcda
2 1
2 2
2 3
2 4
2 5
2 1000000000000000000
1 1 3
a
b
1 1
1 2
1 3
1 1 5
z
z
1 1
1 2
1 3
1 4
1 1000000000000000000
6 4 8
uvwxyz
yvwx
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 400000000000000000
5 4 1
uvwxy
yvwx
2 1



*/

