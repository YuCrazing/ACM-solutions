#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int T, b;
    string a;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        cin >> a >> b;
        b = abs(b);
        int l = a.size();
        long long m = 0;
        for(int i = 0; i < l; i ++){
            if(i == 0 && a[i] == '-') continue;
            m = (m * 10LL + a[i] - '0') % b; // overflow happens if m is int
        }
        cout << "Case " << cas << ": ";
        if(m) cout << "not divisible" << endl;
        else cout << "divisible" <<endl;
    }
    return 0;
}
