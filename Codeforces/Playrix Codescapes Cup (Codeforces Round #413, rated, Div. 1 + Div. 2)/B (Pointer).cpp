/*
    pointer[i] points the position of the cheapest type i T-shirt.
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct Node {
    int p, a, b;
    bool operator<(const Node& t)const {
        return p < t.p;
    }
};
int pointer[3], n, m, x;
Node a[N];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i].p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i].a = x - 1;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i].b = x - 1;
    };
    sort(a, a + n);

    fill(pointer, pointer + 3, 0);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        x--;
        int& pos = pointer[x];
        while(pos < n) {
            if(a[pos].a == x || a[pos].b == x) {
                a[pos].a = a[pos].b = -1;
                printf("%d ", a[pos].p);
                break;
            }
            pos ++;
        }
        if(pos >= n) printf("-1 ");
    }
    return 0;
}
