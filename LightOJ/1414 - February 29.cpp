#include <iostream>
#include <algorithm>
using namespace std;

string MONTH[13] = {
    "Qrz",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

void read(int &month, int &day, int &year) {
    string m, d;
    cin >> m >> d >> year;

    for(int i = 1; i <= 12; i ++) if(m == MONTH[i]) {
            month = i;
            break;
        }

    int l = d.size();
    day = 0;
    for(int i = 0; i < l; i ++) {
        if(d[i] >= '0' && d[i] <= '9') {
            day *= 10;
            day += d[i] - '0';
        } else break;
    }
}

bool isLeap(int year) {
    if(year%100 && year%4 == 0) return true;
    if(year%400 == 0) return true;
    return false;
}

bool isF29(int month, int day, int year) {
    if(isLeap(year) && month == 2 && day == 29) return true;
    return false;
}

int cal(int month, int day, int year) { // cal sum of F29s before the day(inclusive).
    int sum = 0;
    sum += (year - 1)/4 - (year - 1)/100 + (year - 1)/400;
    if(isLeap(year)) {
        if(month > 2) sum ++;
        else if(month == 2 && day == 29) sum ++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T, m, d, y, ans;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++) {
        read(m, d, y);
        ans = cal(m, d, y);
        if(isF29(m, d, y)) ans --;

        read(m, d, y);
        ans = cal(m, d, y) - ans;

        cout << "Case " << cas << ": " << ans << endl;
    }
    return 0;
}
