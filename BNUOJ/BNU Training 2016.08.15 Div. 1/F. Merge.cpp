/*
    K-th min number is the max value among min values of all sets which size is n - K + 1.
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string n2s(int x) {
    string s;
    while(x > 0) {
        s += x%10 + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {

    freopen("merge.in", "r", stdin);
    freopen("merge.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int N = n + m;
    for(int i = 1; i <= N; i ++) {
        int s = N - i + 1;
        string ans;
        for(int minn = 1; minn <= n; minn ++) {
            int num = n - minn + 1;
            if(num + m < s) continue;
            string t;
            t = "x" + n2s(minn);
            if(num < s) {
                t += "&y" + n2s(m - s + num + 1);
                ans += "(" + t + ")|";
            } else ans += t + "|";
        }
        for(int minn = 1; minn <= m; minn ++) {
            int num = m - minn + 1;
            if(num + n < s) continue;
            string t;
            t = "y" + n2s(minn);
            if(num < s) {
                t += "&x" + n2s(n - s + num + 1);
                ans += "(" + t + ")|";

            } else ans += t + "|";
        }
        ans.erase(ans.end() - 1);
//        ans[ans.size() - 1] = 0;
        if(ans.size() > 2000) n/=0;
        cout << ans << endl;
    }
    return 0;
}

