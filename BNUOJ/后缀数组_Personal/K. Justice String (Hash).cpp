#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

//const ull P = 29034862343974; // Wrong Answer.
const ull P = 37; // Accepted.
const int N = 1e5 + 5;
int T, len[2];
char s[2][N];
ull H[128], sum[2][N], p[N];

void init() {
    srand(time(NULL));
    for(int i = 0; i < 128; i++) H[i] = ull(rand()) * ull(rand()) * ull(rand());
    for(int i = 0; i < N; i++) p[i] = (i == 0 ? 1 : p[i-1]*P);
}

ull getHash(int l, int r, int op) {
    assert(l <= r);
    return sum[op][r] - sum[op][l - 1] * p[r - l + 1];
}

bool ok(int x, int y, int l) {
    return getHash(x, x + l - 1, 0) == getHash(y, y + l - 1, 1);
}

int lcp(int x, int y) {
    int l = 0, r = min(len[1] - y, len[0] - x);
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(ok(x, y, mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int calc() {
    for(int i = 0; i < len[0]; i++) {
        if(len[0] - i < len[1]) break;
        int t1 = lcp(i, 0);
        if(t1 >= len[1] - 2) return i;
        int t2 = lcp(i + t1 + 1, t1 + 1);
        if(t1 + t2 >= len[1] - 2) return i;
        int t3 = lcp(i + t1 + 1 + t2 + 1, t1 + 1 + t2 + 1);
        if(t1 + t2 + t3 >= len[1] - 2) return i;
    }
    return -1;
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%s%s", s[0], s[1]);
        for(int k = 0; k < 2; k++) {
            len[k] = strlen(s[k]);
            sum[k][0] = H[s[k][0]];
            for(int i = 1; i < len[k]; i++) sum[k][i] = sum[k][i-1]*P + H[s[k][i]];
        }
        printf("Case #%d: %d\n", ca, calc());
    }
    return 0;
}
