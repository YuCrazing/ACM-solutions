/*
    小于关系需要满足传递性才能排序，不然排序结果不唯一
*/

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

struct P {
    int a, b;
    bool operator<(const P& t)const {
        return (a-1)*t.b<(t.a-1)*b;
    }
};

const int N=1e4+5;
P c[N];

int main() {
    int n, x, T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &x);
        for(int i = 0; i < n; ++i) scanf("%d", &c[i].a);
        for(int i = 0; i < n; ++i) scanf("%d", &c[i].b);
        sort(c, c+n);
        int ans=x;
        for(int i = 0; i < n; ++i) {
            ans = ans*c[i].a%10+c[i].b;
            ans%=10;
        }
        printf("%d\n", ans);
    }
    return 0;
}
