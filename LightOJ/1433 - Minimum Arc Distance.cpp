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

    double length(){
        return sqrt(x * x + y * y);
    }

    void read() {
        cin >> x >> y;
    }
}p[6];

int main(){
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ca++){

        for(int i = 0; i < 3; i++) p[i].read();

        p[3] = p[1] - p[0];
        p[4] = p[2] - p[0];
        p[5] = p[2] - p[1];

        double OA = p[3].length();
        double OB = p[4].length();
        double AB = p[5].length();
        double theta = acos((OA * OA + OB * OB - AB * AB) / (2 * OA * OB));

        cout << "Case " << ca << ": " << setprecision(10) << theta * OA << endl;
    }
    return 0;
}
