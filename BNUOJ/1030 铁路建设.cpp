#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

int sgn(const double& x) {
    if(x > eps) return 1;
    if(x < -eps) return -1;
    return 0;
}

struct Point {
    double x, y;

    Point() {};
    Point(double x, double y):x(x), y(y) {};

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    Point operator+(const Point& b) const {
        return Point(x + b.x, y + b.y);
    }

    Point operator-(const Point& b)const {
        return Point(x - b.x, y - b.y);
    }

    Point operator*(const double& k)const {
        return Point(k * x, k * y);
    }

    double operator*(const Point& b)const {
        return x * b.x + y * b.y;
    }

    double len() {
        return sqrt(x * x + y * y);
    }

    double disToPoint(const Point& b)const {
        return (b - (*this)).len();
    }

    double disToSeg(const Point& a, const Point& b)const {
        Point w = (*this) - a;
        Point v = b - a;
        double c1 = w * v, c2 = v * v;
        if(c1 <= 0) return disToPoint(a);
        if(c1 >= c2) return disToPoint(b);
        return disToPoint(a + v * (c1 / c2));
    }

    bool isOnSeg(const Point& a, const Point& b)const {
        Point c, d;
        if(a.x > b.x) {
            c = b;
            d = a;
        } else {
            c = a;
            d = b;
        }
        if(x < c.x || x > d.x) return false;
        return isOnLine(c, d);
    }

    bool isOnLine(const Point& a, const Point& b)const {
        return abs((x - b.x) * (y - a.y) - (x - a.x) * (y - b.y)) < eps;
    }
};

struct Line {
    Point a, b;
    Line() {};
    Line(Point a, Point b):a(a), b(b) {};

    void read() {
        a.read();
        b.read();
    }

    Point intersection(const Line& t) {
        double x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y;
        double x3 = t.a.x, y3 = t.a.y, x4 = t.b.x, y4 = t.b.y;
        return Point(
                   ((x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4)) / ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4))
                   ,
                   ((x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4)) / ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4))
               );
    }

    Point intersection_BS(const Line& t) { // Binary Search. The intersection must be on segment [t.a, t.b].
        Point l = t.a, r = t.b;
        while((l - r) * (l - r) >= eps * eps) {
            Point mid = l + (r - l) * (1.0 / 2);
            if(sgn(f(mid)) == sgn(f(t.b))) r = mid;
            else l = mid;
        }
        return l;
    }

    double f(const Point& t)const {
        return (t.x - a.x)*(b.y - a.y) - (t.y - a.y)*(b.x - a.x);
    }

    bool isOneSide(const Point& A, const Point B)const {
        int sgnA = sgn(f(A));
        int sgnB = sgn(f(B));
        return sgnA * sgnB > 0;
    }
};

Point A, B, C, D, S, T;
Line L;
int main() {
    int tt;
    double ans;
    scanf("%d", &tt);
    for(int ca = 1; ca <= tt; ca++) {
        A.read();
        B.read();
        C.read();
        D.read();
        L.read();
        S.read();
        T.read();

        if((S.isOnSeg(A, B) && T.isOnSeg(A, B)) || (S.isOnSeg(C, D) && T.isOnSeg(C, D))) ans = 0;
        else {
            Point p1 = L.intersection_BS(Line(A, B));
            Point p2 = L.intersection_BS(Line(C, D));

            if(!L.isOneSide(A, C)) swap(C, D); // A, C is on one side of Line.

            ans = 1e99;

            ans = min(ans, A.disToSeg(C, p2));
            ans = min(ans, p1.disToSeg(C, p2));
            ans = min(ans, C.disToSeg(A, p1));
            ans = min(ans, p2.disToSeg(A, p1));

            ans = min(ans, D.disToSeg(p1, B));
            ans = min(ans, p2.disToSeg(p1, B));
            ans = min(ans, B.disToSeg(p2, D));
            ans = min(ans, p1.disToSeg(p2, D));
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
