#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int T, n, cnt;
map<string, int> mp;
vector<int> son[11111];
queue<int> Q;
int in[11111];

void init() {
    while(!Q.empty()) Q.pop();
    mp.clear();
    cnt = 0;
    memset(in, 0, sizeof(in));
    for(int i = 0; i < 11111; i ++) son[i].clear();
}


int topoSort() {

    int sum = 0;
    for(int i = 0; i < cnt; i ++) if(!in[i]) Q.push(i);

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        sum ++;
        for(vector<int>::iterator it = son[u].begin(); it != son[u].end(); it++) {
            int v = (*it);
            in[v] --;
            if(!in[v]) Q.push(v);
        }
    }
    return (sum == cnt) ? 1 : 0 ;
}

int main() {
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++) {
        cin >> n;
        init();
        for(int i = 0; i < n; i ++) {
            cin >> a >> b;
            if(!mp.count(a)) mp[a] = cnt ++;
            if(!mp.count(b)) mp[b] = cnt ++;
            son[mp[a]].push_back(mp[b]);
            in[mp[b]] ++;
        }
        cout << "Case " << cas << ": " << (topoSort() ? "Yes" : "No") << endl;
    }
    return 0;
}
