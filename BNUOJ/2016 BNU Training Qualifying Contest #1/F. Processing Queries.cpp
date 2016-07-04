//@_@
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 200010;
struct Node {
    int s, d, id;
    bool in;
    ll t;
} a[MAXN];
ll p[MAXN];
queue<Node> Q;
int main() {
    int n, b;
    scanf("%d%d", &n, &b);
    for(int i = 0; i < n; i ++) {
        scanf("%d%d", &a[i].s, &a[i].d);
        a[i].id = i;
        a[i].in = 0;
        a[i].t = 0;
        p[i] = a[i].s;
    }

    Q.push(a[0]);
    a[0].in = 1;
    ll t = a[0].s;
    int mark = 1;
    while(!Q.empty()) {
        Node u = Q.front();
        Q.pop();
        t = max(t, (ll)u.s);
//        printf("%d %d %lld\n",u.id,u.s,t);
        a[u.id].t = t + u.d;
        ll lim = t + u.d - 1;
        int nxt = upper_bound(p, p + n, lim) - p;

        for(int index = max(1 + u.id, mark); index < nxt; index ++) {
            if(b > 0) {
                if(a[index].t != -1 && a[index].in == 0) {
                    if(index == mark) mark ++;
                    Q.push(a[index]);
                    a[index].in = 1;
                    b --;
                }
            } else {
                if(index == mark) mark ++;
                a[index].t = -1;
            }

        }
        nxt = max(nxt, mark);
        while(nxt < n) {
            if(a[nxt].in == 0) {
                a[nxt].in = 1;
                Q.push(a[nxt]);
                if(mark == nxt) mark ++;
                break;
            } else nxt++;
        }
        t += u.d;
    }
    for(int i = 0; i < n; i ++) printf((i == n - 1) ? "%lld\n" : "%lld ",a[i].t);
    return 0;
}
