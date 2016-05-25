#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[111];
string op;
int main(){
    ios_base::sync_with_stdio(0);
    int T, n, m, D, x, y;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
       cin >> n >> m;

        for(int i = 0; i < n; i ++) cin >> a[i];
        while(m --){
            cin >> op;
            if(op == "S"){
                cin >> D;
                for(int i = 0; i < n; i ++) a[i] += D;
            }
            else if(op == "M"){
                cin >> D;
                for(int i = 0; i < n; i ++) a[i] *= D;
            }
            else if(op == "D"){
                cin >> D;
                for(int i = 0; i < n; i ++) a[i] /= D;
            }
            else if(op == "R") reverse(a, a + n);
            else{
                cin >> x >> y;
                swap(a[x], a[y]);
            }
        }
        cout << "Case " << cas << ":" << endl;
        for(int i = 0; i < n; i ++) {
            if(i == n - 1) cout << a[i] << endl;
            else cout << a[i] << " " ;
        }
    }
    return 0;
}
