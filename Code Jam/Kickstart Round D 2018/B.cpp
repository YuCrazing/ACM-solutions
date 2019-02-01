/*
    错误原因：reverse 数组时，没有把 cover 数组 reverse
    优化：两个方向扫一遍，维护一个最大值即可，不需要使用优先队列
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int x, y;

    Node(int _x = 0, int _y = 0):x(_x), y(_y) {}

    bool operator<(const Node & t) const {
        return x < t.x;
    }
};

const int N = 1e5 + 5;
int A, B, C, M, n, k, T;
Node a[N], b[N];
bool cover[N];

//int brute() {
//    int sum = 0;
//    for(int j = 1; j <= k; ++j) {
//        bool ok = false;
//        int id;
//        for(int i = 1; i <= n; ++i) {
//            if(a[i].y >= b[j].y + abs(a[i].x - b[j].x)) {
//                ok = true;
//                id = i;
//                break;
//            }
//        }
//        printf("%d %d\n", j, cover[j]);
//        if(ok && cover[j] == false) {
//            printf("#(%d %d)\n", a[id].x, a[id].y);
//            printf("#(%d %d)\n", b[j].x, b[j].y);
//        }
//        sum += ok;
//    }
//    return sum;
//}

int main() {

    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &k);

        scanf("%d%d%d%d%d%d", &a[1].x, &a[2].x, &A, &B, &C, &M);
        for(int i = 3; i <= n; ++i) a[i].x = ((ll)A * a[i-1].x + (ll)B * a[i-2].x + C) % M + 1;

        scanf("%d%d%d%d%d%d", &a[1].y, &a[2].y, &A, &B, &C, &M);
        for(int i = 3; i <= n; ++i) a[i].y = ((ll)A * a[i-1].y + (ll)B * a[i-2].y + C) % M + 1;

        scanf("%d%d%d%d%d%d", &b[1].x, &b[2].x, &A, &B, &C, &M);
        for(int i = 3; i <= k; ++i) b[i].x = ((ll)A * b[i-1].x + (ll)B * b[i-2].x + C) % M + 1;

        scanf("%d%d%d%d%d%d", &b[1].y, &b[2].y, &A, &B, &C, &M);
        for(int i = 3; i <= k; ++i) b[i].y = ((ll)A * b[i-1].y + (ll)B * b[i-2].y + C) % M + 1;


        for(int i = 1; i <= k; ++i) cover[i] = false;

        int mx = -2e9;
        sort(a + 1, a + n + 1);
        sort(b + 1, b + k + 1);
        int i = n, j = k;

        while(j) {
            if(i) {
                if(b[j].x > a[i].x) {
                    if(b[j].y - b[j].x <= mx) cover[j] = true;
                    --j;
                } else {
                    mx = max(a[i].y - a[i].x, mx);
                    --i;
                }
            } else {
                if(b[j].y - b[j].x <= mx) cover[j] = true;
                --j;
            }
        }

        mx = -2e9;
        reverse(a + 1, a + n + 1);
        reverse(b + 1, b + k + 1);
        reverse(cover + 1, cover + k + 1);
        i = n, j = k;

        while(j) {
            if(i) {
                if(b[j].x < a[i].x) {
                    if(b[j].y + b[j].x <= mx) cover[j] = true;
                    --j;
                } else {
                    mx = max(a[i].y + a[i].x, mx);
                    --i;
                }
            } else {
                if(b[j].y + b[j].x <= mx) cover[j] = true;
                --j;
            }
        }

        int ans = 0;
        for(int i = 1; i <= k; ++i) ans += cover[i];
        printf("Case #%d: %d\n", ca, ans);

    }
    return 0;
}
