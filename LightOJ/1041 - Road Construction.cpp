#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string s1, s2;
map<string, int> mp;

struct Edge {
    int u, v, w;
    Edge(int _u = 0, int _v = 0, int _w = 0):u(_u), v(_v), w(_w) {};

    bool operator<(const Edge& b)const {
        return w < b.w;
    }

} e[55];

int n, fa[100];

void init() {
    mp.clear();
    n = 0;
    for(int i = 0; i < 100; i ++) fa[i] = i;
}

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    ios_base::sync_with_stdio(false);

    int T, m, w, u, v;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++) {
        init();
        cin >> m;
        for(int i = 0; i < m; i ++) {
            cin >> s1 >> s2 >> w;
            if(!mp.count(s1)) mp[s1] = n ++;
            if(!mp.count(s2)) mp[s2] = n ++;
            u = mp[s1];
            v = mp[s2];
            e[i] = Edge(u, v, w);
        }

        sort(e, e + m);
        int cc = n, sum = 0;
        for(int i = 0; i < m; i ++) if(find(e[i].u) != find(e[i].v)) {
                sum += e[i].w;
                merge(e[i].u, e[i].v);
                cc --;
            }

        cout << "Case " << cas << ": ";
        if(cc > 1) cout << "Impossible";
        else cout << sum;
        cout << endl;
    }
    return 0;
}
