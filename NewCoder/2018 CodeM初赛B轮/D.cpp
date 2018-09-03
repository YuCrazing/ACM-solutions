#include<bits/stdc++.h>
#define fi first
#define se second
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double eps=1e-8;

struct P{
    double x, y;
};

double len(P & a, P & b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

P s, t;
double r;

double calc(double theta){
    P a, b;
    a.x=r*cos(theta);
    a.y=r*sin(theta);
    b.x=-a.x;
    b.y=-a.y;
    return len(a, s) + len(b, t);
}

double solve(){
    double r = 2*pi, l = 0, ll, rr;
    P a, b;
    while(fabs(l-r)>eps){
        ll = (2*l+r)/3;
        rr = (l+2*r)/3;
        if(calc(ll) > calc(rr)) l=ll;
        else r=rr;
    }
    return calc(l);
}

int main(){
    scanf("%lf", &r);
    scanf("%lf%lf", &s.x, &s.y);
    scanf("%lf%lf", &t.x, &t.y);

    double ans = min(len(s, t), calc(0));
    ans = min(ans, solve());
    printf("%.10f\n", ans);

    return 0;
}
