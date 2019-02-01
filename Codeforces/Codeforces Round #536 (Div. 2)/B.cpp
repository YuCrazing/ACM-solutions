/*
    使用链表思想也可以
*/

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

const int N = 1e5 + 5;
int a[N], c[N];

struct Node {
    int cost, ind;
    bool operator<(const Node & t)const {
        if(cost == t.cost) return ind < t.ind;
        return cost < t.cost;
    }
};
set<Node> mp;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
        mp.insert({c[i], i});
    }

    int id, num;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &id, &num);
        ll sum = 0;
        while(num && mp.size()) {
            if(a[id] == 0) {
                auto it = mp.begin();
                id = it->ind;
            } else {
                auto it = mp.find({c[id],id});
                if(a[id] > num) {
                    sum += (ll) num * c[id];
                    a[id] -= num;
                    num = 0;
                } else {
                    sum += (ll) a[id] * c[id];
                    num -= a[id];
                    a[id] = 0;
                    mp.erase({c[id], id});
                }
            }
        }
        if(num) sum = 0;
        printf("%I64d\n", sum);
    }

    return 0;
}

