#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;


struct Node {
    int p, a, b;
    bool operator<(const Node& t)const {
        return p < t.p;
    }
};

set<Node> st[3];
Node a[N];
int main() {
    int n, m, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i].p);
    for(int i = 0; i < n; i++) scanf("%d", &a[i].a);
    for(int i = 0; i < n; i++) scanf("%d", &a[i].b);

    for(int i = 0; i < n; i++) {
        a[i].a --;
        a[i].b --;
        if(a[i].a == a[i].b) {
            st[a[i].a].insert(a[i]);
        } else {
            st[a[i].a].insert(a[i]);
            st[a[i].b].insert(a[i]);
        }
    }


    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        x --;
        if(st[x].empty()) printf("-1 ");
        else {
            Node t = *st[x].begin();
            printf("%d ", t.p);
            st[x].erase(t);
            if(t.a != t. b) {
                if(x == t.a) st[t.b].erase(t);
                else st[t.a].erase(t);
            }
        }
    }

    return 0;
}
