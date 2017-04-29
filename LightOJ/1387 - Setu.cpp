#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, n, x, sum;
    string op;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        cin >> n;
        cout << "Case " << ca << ":" << endl;
        sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> op;
            if(op[0] == 'd') {
                cin >> x;
                sum += x;
            } else cout << sum << endl;
        }
    }
    return 0;
}
