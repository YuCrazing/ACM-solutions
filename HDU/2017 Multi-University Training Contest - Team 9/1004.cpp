#include<bits/stdc++.h>
using namespace std;
typedef double db;

const int N = 1010;
const db eps = 1e-8;

int sgn(db x) {
    if(fabs(x) < eps) return 0;
    if(x > eps) return 1;
    return -1;
}

struct Point {
    db x, y;
    Point(db _x=0, db _y=0):x(_x),y(_y) {}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    Point operator+(const Point &t) const {
        return Point (x+t.x, y+t.y);
    }
    Point operator-(const Point &t) const {
        return Point (x-t.x, y-t.y);
    }
    db operator*(const Point &t) const {
        return x*t.x+y*t.y;
    }
    db operator^(const Point &t) const {
        return x*t.y-y*t.x;
    }
    Point operator*(const db t) const {
        return Point(x*t, y*t);
    }
    bool operator==(const Point& t) const {
        return sgn(x-t.x)==0&&sgn(y-t.y)==0;
    }
    db len()const {
        return sqrt(x*x+y*y);
    }
    Point normalize()const {
        return Point(x/len(), y/len());
    }

};

struct Segment {
    int a, b;
    db k;
};

struct Light {
    Point dir, ori;
    db val;
};

Point p[N];
Segment l[N];
Light light;
int n;

bool inside(Point po) {
    Point u, v;
    for(int i = 0; i < n; i++) {
        u = p[l[i].b]-p[l[i].a];
        v = po - p[l[i].a];
        if(sgn(u^v)<0) return false;
    }
    return true;
}

bool intersection(Light& ray, int id) {

    Point a = ray.ori;
    Point b = ray.ori+(ray.dir*1e10);

    Point c = p[l[id].a];
    Point d = p[l[id].b];

    if((sgn((c-d)^(a-d)) != sgn((c-d)^(b-d))) && (sgn((a-b)^(c-b)) != sgn((a-b)^(d-b)))) {
        if(sgn(ray.dir^(c-a)) == 0) {
            ray.ori = c;
            ray.dir = Point(0, 0);
        } else if(sgn(ray.dir^(d-a)) == 0) {
            ray.ori = d;
            ray.dir = Point(0, 0);
        } else {
            Point u = d-c;
            int sg = sgn((a-c)^u);
            db l = 0, r = 1e90;
            while(fabs(l-r)>=eps) {
                db mid = (l+r)/2;
                if(sg*sgn((a+(ray.dir*mid)-c)^u)>=0) l = mid;
                else r = mid;
            }
            Point inter = a+(ray.dir*l);
            Point norm = Point(-u.y, u.x).normalize();

            ray.ori = inter;
            ray.dir = ray.dir-norm*((ray.dir*norm)*2);
        }
        ray.val *= l[id].k;
        return true;
    }
    return false;
}

int calc(Light& ray, int id) {
    for(int i = 0; i < n; i++)
        if(i!=id) {
            if(intersection(ray, i)) return i;
        }
    return -1;
}

int main() {
    while(scanf("%d", &n)!=EOF) {
        for(int i = 0; i < n; i++) {
            p[i].read();
            scanf("%lf", &l[i].k);
            l[i].a = i;
            l[i].b = (i+1)%n;
        }
        light.ori = Point(0, 0);
        light.val = 1.0;
        light.dir.read();

        int id, ans=0;
        if(inside(light.ori)) {
            id = -1;
            while(sgn(light.val-(1e-4))>=0) {
                id = calc(light, id);
                ans++;
                if(light.dir == Point(0, 0)) break;
            }
        } else {
            id = calc(light, id);
            if(id==-1) ans = 0;
            else ans = 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}
/*
4
1 1 0.5
2 1 0.5
2 2 0.5
1 2 0.5
1 1
*/
