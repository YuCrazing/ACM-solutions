/*
    Line-plane intersection:

    Line: p = k*l + l0. (k is a real number scalar, l is direction vector of the line, l0 is a point on the line.)
    Plane: (p - p0)*n = 0. (n is normal vector of the plane, p0 is a point on the plane.)

    intersection: d*l + l0.(d = ((l0 - p0)*n)/(l*n))

    https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
*/
#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

int sgn(double x) {
    if(x >= eps) return 1;
    if(x <= -eps) return -1;
    return 0;
}

struct Point {
    double x, y, z;

    Point() {
        x = y = z = 0;
    };

    Point(double x, double y, double z):x(x),y(y),z(z) {};

    bool operator==(const Point& t)const {
        return (t - (*this)).len() < eps;
    }

    bool sameDir(const Point& t)const {
        return ((t ^ (*this)).len() < eps) && (t * (*this) >= 0);
    }

    Point operator+(const Point& t)const {
        return Point(x + t.x, y + t.y, z + t.z);
    }

    Point operator-(const Point& t)const {
        return Point(x - t.x, y - t.y, z - t.z);
    }

    Point operator*(const double& k)const {
        return Point(k * x, k * y, k * z);
    }

    double operator*(const Point& t)const {
        return x * t.x + y * t.y + z * t.z;
    }

    Point operator^(const Point& t)const {
        return Point(
                   y*t.z - z*t.y,
                   z*t.x - x*t.z,
                   x*t.y - y*t.x
               );
    }

    double len() {
        return sqrt((*this) * (*this));
    }

    void read()const {
        scanf("%lf%lf%lf", &x, &y, &z);
    }

    void print()const {
        printf("%.2f %.2f %.2f\n", x, y, z);
    }

};

struct Plane {
    double A, B, C, D;
    Point normal, P0;

    Plane() {};

    Plane(Point a, Point b, Point c) {

        P0 = a; // A point on the plane.

        Point p0 = b - a;
        Point p1 = c - a;

        normal = p0 ^ p1;
        assert(normal.len() >= eps);

        A = normal.x;
        B = normal.y;
        C = normal.z;
        D = -(A*a.x + B*a.y + C*a.z);
    };

    double f(const Point& a)const {
        return A*a.x + B*a.y + C*a.z + D;
    }

    bool parallel(const Point& a)const {
        return abs(a * normal) < eps;
    }

    /* Intersection with Line ab. If no intersection, return (0, 0, 0). */
    Point intersection(const Point &a, const Point& b)const {
        Point l = b - a;
        if(abs((l * normal)) < eps && sgn(f(a)) == 0) assert(0); // Line is on the plane.
        if(abs((l * normal)) < eps) return Point(); // Line is parallel with plane.

        double d = ((P0 - a)*normal) / (l*normal);
        if(d < 0) return Point(); // No intersection with ray a->b.
        return l*d + a;
    }

};
int main() {
    Point dir, head, p[3];
    Plane glass;

    dir.read();
    head.read();
    for(int i = 0; i < 3; i++) p[i].read();
    glass = Plane(p[0], p[1], p[2]);

    printf((dir.sameDir(head)) ? "Yes\n" : "No\n"); // Parallel and same direction.

    assert(sgn(glass.f(Point())));

//    Point l = Point(), r = dir * (1e20);
//    if(sgn(glass.f(l)) * sgn(glass.f(r)) > 0) {
//        printf("No\n");
//    } else {
//        while((r - l).len() >= eps) {
//            Point mid = l + (r - l) * 0.5;
//            if(sgn(glass.f(mid)) * sgn(glass.f(Point())) <= 0) r = mid;
//            else l = mid;
//        }
//        l.print();
//    }

    Point intersection = glass.intersection(Point(), dir);
    if(intersection == Point()) printf("No\n");
    else intersection.print();

    return 0;
}

/*
1 1 1
-1 -1 -1
-2 0 0
0 -2 0
0 0 -2
*/
