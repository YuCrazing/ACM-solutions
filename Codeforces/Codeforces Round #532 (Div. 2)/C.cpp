#include <bits/stdc++.h>
using namespace std;
typedef long double db;

const db pi = 3.14159265358979323846264338327950288419716939937510582097494;

int main() {
    int n;
    db r;
    cin >> n >> r;
    db x = sin(pi/n);
    cout << setprecision(20) << r*x/(1-x) << endl;
    return 0;
}
