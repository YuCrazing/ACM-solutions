#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Node {
    int x, v, i;
    bool operator<(const Node& t)const {
        return v > t.v;
    }
};

bool cmp(const Node& a, const Node& b) {
    return a.x < b.x;
}

Node a[N];
int T, n, k;
priority_queue<Node> q;
int main() {

//    freopen("1084.in", "r", stdin);
//    freopen("1084.out", "w", stdout);

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i].x);

        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; i++) a[i].i = i; // After sort !!!

        a[0].i = a[0].v = 0;
        a[0].x = a[1].x;
        a[1].v = a[2].v = -1;

        while(!q.empty()) q.pop();
        q.push(a[0]); // If can cover all people in [1, i], a[i].v = 1;

        for(int i = 3; i <= n; i++) {
            while(!q.empty() && (q.top().v < 0 || a[i].x - a[q.top().i + 1].x > 2 * k)) q.pop();

            if(q.empty()) {
                a[i].v = -1;
            } else {
                a[i].v = q.top().v + 1;
            }

            q.push(a[i - 2]); //
        }

        printf("Case %d: %d\n", ca, a[n].v);
    }
    return 0;
}

/*

100
6 1
1 2 3 5 6 7
7 1
1 2 3 10 13 14 15
8 2
1 2 3 4 7 8 9 10
8 10
1 2 3 4 5 6 7 8
10 2
24 22 20 4 21 3 25 2 23 1

*/
