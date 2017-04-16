#include<bits/stdc++.h>
using namespace std;
/*
    注意cout 默认只保留六位有效位数（加上整数部分），
    需要setprecision才能保证小数位数
*/

double r[3], l[3], theta[3], area;
double aacos(double a, double b, double c){
    return acos((a * a + b * b - c * c) / (2 * a * b));
}
int main(){

    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ca++){

        cin >> r[0] >> r[1] >> r[2];

        l[0] = r[0] + r[1];
        l[1] = r[0] + r[2];
        l[2] = r[1] + r[2];

        theta[0] = aacos(l[0], l[1], l[2]);
        theta[1] = aacos(l[0], l[2], l[1]);
        theta[2] = aacos(l[1], l[2], l[0]);

//        area = sin(theta[0]) * l[0] * l[1] / 2;
        area = sqrt((r[0] + r[1] + r[2]) * r[0] * r[1] * r[2]); //Heron's formula
        for(int i = 0; i < 3; i++) area -= theta[i] * r[i] * r[i] / 2;

//        cout << "Case " << ca << ": " << setprecision(10) << area << endl; // setprecision() is necessary.
        printf("Case %d: %f\n", ca, area);
//        cout << "Case " << ca << ": " << area << endl;
    }
    return 0;
}
