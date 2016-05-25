#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T, n;
    string name;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        cin >> n >> name;
        cout << "Case " << cas << ": ";
        if(name == "Alice"){
            if(n % 3 == 1) cout << "Bob";
            else cout << "Alice";
        }
        else {
            if(n % 3 == 0) cout << "Alice";
            else cout << "Bob";
        }
        cout << endl;
    }
    return 0;
}
