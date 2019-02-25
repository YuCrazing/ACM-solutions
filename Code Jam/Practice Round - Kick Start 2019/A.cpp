#include <bits/stdc++.h>
using namespace std;

int out(int x) {
    cout << x << endl;
    cout.flush();

    string s;
    cin >> s;

    if(s == "CORRECT") return 0;
    if(s == "TOO_SMALL") return 1;
    if(s == "TOO_BIG") return 2;
    return 3;
}

int main() {
    int T, l, r, n;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {
        cin >> l >> r >> n;
        ++l;

        while(l <= r) {
            int mid = (l+r)/2;
            int res = out(mid);
            if(res == 0) break;

            if(res == 1) l = mid+1;
            else r = mid-1;
        }
    }

    return 0;
}
