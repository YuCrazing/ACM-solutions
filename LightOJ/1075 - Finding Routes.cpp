#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mp;
int a[400];
string s[400];
bool vis[400];
int main() {
    ios_base::sync_with_stdio(false);
    int T, n, cnt, u, v;
    string su, sv;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++) {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        mp.clear();
        cnt = 0;

        for(int i = 0; i < n - 1; i ++) {
            cin >> su >> sv;
            if(mp.count(su)) u = mp[su];
            else {
                s[cnt] = su;
                u = mp[su] = cnt ++;
            }
            if(mp.count(sv)) v = mp[sv];
            else {
                s[cnt] = sv;
                v = mp[sv] = cnt ++;
            }
            vis[v] = 1;
            a[u] = v;
        }
        int src;
        for(int i = 0; i < cnt; i ++) if(!vis[i]) {
                src = i;
                break;
            }
        cout << "Case " << cas << ":" <<endl;
        n --;
        u = src;
        while(n > 0) {
            cout << s[u] << endl;
            u = a[u];
            if(n == 1) cout << s[u] << endl;
            n --;
        }
        cout << endl;
    }
    return 0;
}
