#include<bits/stdc++.h>
using namespace std;

string name[2], buf[2];
int main() {
    int T;
    cin >> T;
    cin.ignore();
    for(int ca = 1; ca <= T; ca++) {
        for(int k = 0; k < 2; k++) {
            name[k].clear();
            getline(cin, buf[k]);
            int l = buf[k].size();
            for(int i = 0; i < l; i++) if(buf[k][i] != ' ') {
                    if(isupper(buf[k][i])) name[k] += tolower(buf[k][i]);
                    else name[k] += buf[k][i];
                }
            sort(name[k].begin(), name[k].end());
        }
        cout << "Case " << ca << ": " << (name[0] == name[1] ? "Yes" : "No") << endl;
    }
    return 0;
}
