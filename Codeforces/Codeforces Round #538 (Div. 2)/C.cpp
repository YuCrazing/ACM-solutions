/*
    求一个数的所有素因子不需要筛素数
*/

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef double db;

vector< pair<ll, int> > divs;

int main() {

    ll n, b;
    scanf("%I64d%I64d", &n, &b);

    for(ll i = 2; ; ++i) {
        if(b%i == 0) {
            int cnt = 0;
            while(b%i==0) {
                b /= i;
                ++cnt;
            }
            divs.push_back({i, cnt});
        }
        if(i * i > b) {
            if(b != 1) divs.push_back({b, 1});
            break;
        }
    }


    ll sum, mi = 1000000000000000001LL;
    for(int i = 0; i < divs.size(); ++i) {
        sum = 0;
        ll t = n;
        while(t) {
            sum += t / divs[i].fi;;
            t /= divs[i].fi;
        }
        mi = min(mi, sum / divs[i].se);
    }


    // 这种写法也对
//    ll inf = 1000000000000000001LL; // 防止溢出
//    for(int i = 0; i < divs.size(); ++i) {
//        b = divs[i].fi;
//        sum = 0;
//        while(n/b) {
//            sum += n/b;
//            if(b <= inf/divs[i].fi) b *= divs[i].fi; // 之前写成了 if(b <= inf/b) b *= b; ... 完全不等价
//            else b = inf;
//        }
//        mi = min(mi, sum / divs[i].se);
//    }

    printf("%I64d\n", mi);
    return 0;
}
/*
    10000000 1000000007
    1000000007 2000000014
    100000000007 100000000007
*/
