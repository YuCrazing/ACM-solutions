#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
/*
    index range in RMQ is sooooooooooooooooooooooooooooooooo important!
*/
const int N = 1e5 + 4;
struct Node {
    int v, w;
    Node() {};
    Node(int v, int w):v(v),w(w) {};

    bool operator<(const Node& t)const {
        return w < t.w;
    }
};
vector<Node> a[2];
int dp[2][N][17];
int b[2][N];
void init() {
    for(int k = 0; k < 2; k++) {
        int n = a[k].size();
        for(int i = 0; i < n; i++) dp[k][i][0] = a[k][i].v;
        for(int j = 1; (1 << j) <= n; j++) {
            for(int i = 0; i + (1<<j) - 1 < n; i++) {
                dp[k][i][j] = max(dp[k][i][j - 1], dp[k][i + (1<<(j - 1))][j - 1]);
            }
        }
    }
}

int RMQ(int k, int l, int r) {
    int j = 0;
    while((1<<j) <= (r - l + 1)) j++;
    j--;
    return max(dp[k][l][j], dp[k][r - (1<<j) + 1][j]);
}

char s[5];
int vv, ww;
int main() {
    int n, c, d;
    scanf("%d%d%d", &n, &c, &d);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%s", &vv, &ww, s);
        if(s[0] == 'C') a[0].push_back(Node(vv, ww));
        else  a[1].push_back(Node(vv, ww));
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    init();

    for(int k = 0; k < 2; k ++)
        for(int i = 0; i < a[k].size(); i++) {
            b[k][i] = a[k][i].w;
//            printf("%d %d %d\n", k, i, b[k][i]);
        }


    int r1 = upper_bound(b[0], b[0] + a[0].size(), c) - b[0] - 1;
    int r2 = upper_bound(b[1], b[1] + a[1].size(), d) - b[1] - 1;
//    printf("%d %d\n", r1, r2);
    int ans = 0;
    if(r1 < 0 || r2 < 0 || a[0].size() < 1 || a[1].size() < 1 ) {

    } else {
        ans = RMQ(0, 0, r1) + RMQ(1, 0, r2);
//        printf("%d %d\n", RMQ(0, 0, r1) , RMQ(1, 0, r2));
    }

    int w[2];
    w[0] = c;
    w[1] = d;

    for(int k = 0; k < 2; k++) {
        if(a[k].size() > 1) {
            for(int i = 0; i < a[k].size(); i++) {
                if(a[k][i].w < w[k]) {
                    int left = w[k] - a[k][i].w;
                    if(left < a[k][i].w) break;
//                    int r = upper_bound(a[k].begin(), a[k].end(), left) - a[k].begin() - 1;
                    int r = upper_bound(b[k], b[k] + a[k].size(), left) - b[k] - 1;
                    if(r <= i) break;
                    if(r < 0) break;
                    ans = max(ans, a[k][i].v + RMQ(k, i + 1, r));
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
