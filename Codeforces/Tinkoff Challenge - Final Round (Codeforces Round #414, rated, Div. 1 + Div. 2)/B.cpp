#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    double h, x;
    int n;
    scanf("%d%lf", &n, &h);
    double s = h*1.0 / (n) / 2;
    double l = 0.0, sum = 0;
    for(int i = 0; i < n - 1; i++) {
        double b = (l - sum / h);
        x = h * (sqrt(b * b + 4 * (l * sum + 2 * s) / h) - b) / 2;
        sum = x;
        printf("%.10f ",sum);
//        printf("%.10f ",sum);
        l = x / h;
    }

    return 0;
}
