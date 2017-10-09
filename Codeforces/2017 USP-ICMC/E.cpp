#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e5+10;
struct Point {

    ll x, y;
    int id;

    Point(ll _x=0,ll _y=0):x(_x),y(_y) {}

    void read() {
        scanf("%I64d%I64d", &x, &y);
    }

    ll operator^(const Point &t)const {
        return x*t.y-y*t.x;
    }

    Point operator+(const Point &t)const {
        return Point(x+t.x, y+t.y);
    }

    Point operator-(const Point &t)const {
        return Point(x-t.x, y-t.y);
    }
    ll dis2() {
        return x*x+y*y;
    }
};

Point listt[MAXN];

int Stack[MAXN], top;

ll dist(Point& a, Point &b) {
    return (a-b).dis2();
}

int sgn(ll x) {
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
}

bool _cmp(Point p1, Point p2) {
    ll tmp=(p1-listt[0])^(p2-listt[0]);
    if(sgn(tmp)>0) return true;
    else if(sgn(tmp)==0&&sgn(dist(p1, listt[0])-dist(p2, listt[0]))<=0)
        return true;
    else return false;
}

void Graham(int n) {
    Point p0;
    int k=0;
    p0=listt[0];
    for(int i = 1; i < n; i++) {
        if( (p0.y>listt[i].y) || (p0.y == listt[i].y && p0.x > listt[i].x) ) {
            p0=listt[i];
            k=i;
        }
    }

    swap(listt[k], listt[0]);
    sort(listt+1, listt+n, _cmp);
    if(n==1) {
        top=1;
        Stack[0]=0;
        return;
    }
    if(n==2) {
        top=2;
        Stack[0]=0;
        Stack[1]=1;
        return ;
    }
    Stack[0]=0;
    Stack[1]=1;
    top=2;
    for(int i=2; i < n; i++) {
        while(top>1 && sgn((listt[Stack[top-1]]-listt[Stack[top-2]]) ^(listt[i]-listt[Stack[top-2]])) < 0)
            top--;
        Stack[top++]=i;
    }
}
bool vis[MAXN];
int main() {
    top=0;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n+m; i++) {
        listt[i].read();
        listt[i].id=i;
    }
    Graham(n+m);
    bool ok=true;
    //for(int i = 0; i < top; i++) printf("%d %d\n",i, listt[Stack[i]].id);
    memset(vis, 0, sizeof(vis));

    for(int i = 0; i < top; i++) vis[listt[Stack[i]].id]=true;

    if(vis[0]==true) {
        for(int i = 0; i < n; i++) if(vis[i]==false) {
                ok=false;
                break;
            }
        for(int i = n; i < n + m; i++) if(vis[i]==true) {
                ok=false;
                break;
            }
    } else if(vis[n]==true) {
        for(int i = 0; i < n; i++) if(vis[i]==true) {
                ok=false;
                break;
            }
        for(int i = n; i < n + m; i++) if(vis[i]==false) {
                ok=false;
                break;
            }
    } else ok=false;

    printf(ok?"YES\n":"NO\n");
}
/*


4 3
0 0
2 0
0 2
2 2
1 0
0 1
2 1


*/
