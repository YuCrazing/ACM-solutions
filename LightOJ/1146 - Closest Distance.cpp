#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0):x(_x),y(_y) {};

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    Point operator+(const Point& b)const {
        return Point(x + b.x, y + b.y);
    }

    Point operator-(const Point& b)const {
        return Point(x - b.x, y - b.y);
    }
    Point operator*(const double& k)const {
        return Point(k * x, k * y);
    }

    double abs2() {
        return x * x + y * y;
    }

    void show() {
        printf("(%f, %f)\n", x, y);
    }
};

Point A, B, C, D, v1, v2;

double calc(double k) {
    Point p1 = A + v1 * k;
    Point p2 = C + v2 * k;
    return (p2 - p1).abs2();
}

int main() {

    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        A.read();
        B.read();
        C.read();
        D.read();
        v1 = B - A;
        v2 = D - C;
        double l = 0, r = 1;
        int t = 60;
        for(int i = 0; i < t; i ++) {
            double x = (2 * l + r) / 3;
            double y = (l + r * 2) / 3;
            if(calc(x) > calc(y)) l = x;
            else r = y;
        }
        printf("Case %d: %.10f\n", cas, sqrt(calc(l)));
    }
    return 0;
}
