#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0):x(x), y(y) {};

    Point operator+(const Point b)const {
        return Point(x + b.x, y + b.y);
    }

    Point operator-(const Point b)const {
        return Point(x - b.x, y - b.y);
    }

    int operator^(const Point b)const {
        return abs(x * b.y - y * b.x);
    }

    void read() {
        cin >> x >> y;
    }
};

Point p[4];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        for(int i = 0; i < 3; i++) p[i].read();
        p[3] = p[0] + p[2] - p[1];
        cout << "Case " << ca << ": " << p[3].x << " " << p[3].y << " " << ((p[2] - p[1])^(p[0] - p[1])) << endl;
    }
    return 0;
}
