#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

const int N = 1e5 + 3;
bool vis[N];
int tol, cur, ans;

int getid(string name) {
    if(mp.find(name) == mp.end()) mp[name] = tol++;
    return mp[name];
}

void init() {
    memset(vis, 0, sizeof(vis));
    mp.clear();
    tol = cur = ans = 0;
}

int T, n;
string op, name;
int main() {
    scanf("%d", &T);
    while(T--) {

        init();

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> op >> name;
            if(op == "in") {
                getid(name);
            } else {
                int id = getid(name);
                if(id == cur) {
                    ans++;
                    vis[cur] = 1;
                    while(vis[cur]) cur++;
                } else {
                    vis[id] = 1;
                }
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}
