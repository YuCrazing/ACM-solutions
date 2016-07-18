#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;


const int MAXN = 1e5 + 2;
const ll MOD = 998244353;
struct Node {
    ll x, y;
    bool operator <(const Node& b)const {
        return y - x < b.y - b.x;
    }
} p[MAXN];
int lim[MAXN][2], a[MAXN];
ll vis[MAXN];
int main() {
    int T, n;
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &n);
        for(int i = 0; i < n;  i++) scanf("%d", &lim[i][0]);
        for(int i = 0; i < n;  i++) scanf("%d", &lim[i][1]);

        bool ok = 1;
        ll ans = 1;
        if(lim[0][0] != lim[0][1]) ok = 0;
        else {
            a[0] = lim[0][0];
            for(int i = 1; i < n; i ++) {
                if(lim[i][0] != lim[i - 1][0] && lim[i][1] !=lim[i - 1][1]) {
                    ok = 0;
                    break;
                } else if(lim[i][0] != lim[i - 1][0]) {
                    if(lim[i][0] > lim[i - 1][0]) {
                        ok = 0;
                        break;
                    }
                    a[i] = lim[i][0];
                } else if(lim[i][1] != lim[i - 1][1]) {
                    if(lim[i][1] < lim[i - 1][1]) {
                        ok = 0;
                        break;
                    }
                    a[i] = lim[i][1];
                } else a[i] = -1;
            }
        }
        if(lim[n - 1][0] != 1 || lim[n - 1][1] != n) ok = 0;
        if(ok) {
            ll ct = 0;
            for(int i = 0; i < n; i ++) {
                if(a[i] == -1) {
                    p[ct ].x = lim[i][0];
                    p[ct ++].y = lim[i][1];
                }
            }

            if(ct != 0) {
                for(int i = 0; i <= n ; i ++) vis[i] = 0;
                for(int i = 0;  i < n; i ++) if(a[i] != -1) vis[a[i]] = 1;
                for(int i = 0; i <= n; i ++) {
                    vis[i] += vis[i - 1];
                }
                sort(p, p + ct);
                for(ll i = 0; i < ct; i ++) ans = ((p[i].y - p[i].x - 1) - (vis[p[i].y - 1] - vis[p[i].x]) - i) * ans % MOD;
            }
            printf("%I64d\n", ans);
        } else printf("0\n");
    }
    return 0;
}

/*
100
5
1 1 1 1 1
1 5 5 5 5
3
2 1 1
2 2 3
5
5 4 3 2 1
1 2 3 4 5
6
2 2 2 2 2 1
2 6 6 6 6 6
6
5 4 4 3 2 1
5 5 6 6 6 6
6
2 2 2 1 1 1
2 6 6 6 6 6
*/


//solution:

//#include <cstdio>
//#include <iostream>
//using namespace std;
//const int maxn=100005;
//typedef long long ll;
//const ll mod=998244353;
//int T, n, B[maxn], C[maxn];
//ll res;
//int main()
//{
//    //freopen("in.txt", "r", stdin);
//    scanf("%d", &T);
//    while (T--) {
//        res=1;
//        scanf("%d", &n);
//        for (int i=0; i<n; i++)
//            scanf("%d", &B[i]);
//        for (int i=0; i<n; i++)
//            scanf("%d", &C[i]);
//        bool flag=false;
//        if (C[0]!=B[0]) {
//            puts("0");
//            continue;
//        }
//        for (int i=1; i<n; i++)
//            if (B[i]>B[i-1]||C[i]<C[i-1]) {
//                puts("0");
//                flag=true;
//                break;
//            }
//        if (flag)
//            continue;
//        for (int i=1; i<n; i++) {
//            if (C[i]!=C[i-1]&&B[i]!=B[i-1]) {
//                puts("0");
//                flag=true;
//                break;
//            } else if (C[i]==C[i-1]&&B[i]==B[i-1])
//                res=(res*(ll)(C[i]-B[i]-i+1))%mod;
//        }
//        if (flag)
//            continue;
//        cout<<res<<endl;
//    }
//    return 0;
//}

