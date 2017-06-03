#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int L = 5005;
const ull P = 3453475893457; // Random.
int T, len[3];
char s[3][L];
ull sum[3][L], p[L];
set<ull> st[3];

void init() {
    p[0] = 1;
    for(int i = 1; i < L; i++) p[i] = p[i - 1] * P;
}

bool ok(int x) {
    if(!x) return true;

    st[0].clear();
    st[1].clear();
    st[2].clear();

    int n = max(len[0], max(len[1], len[2]));

    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < len[k] - x + 1; i++) {
            ull t = sum[k][i+x-1] - (i<1 ? 0 : sum[k][i-1]*p[x]);
            st[k].insert(t);
        }
    }

    for(set<ull>::iterator it = st[0].begin(); it != st[0].end(); it++) {
        if(st[1].find(*it) != st[1].end()) {
            st[2].insert(*it);
        }
    }

    for(int i = 0; i < len[2] - x + 1; i++) {
        ull t = sum[2][i+x-1] - (i<1 ? 0 : sum[2][i-1]*p[x]);
        if(st[2].find(t) != st[2].end()) return true;
    }
    return false;
}

int BS() {
    int l = 0, r = min(min(len[0], len[1]), len[2]);
    while(l < r) {
        int mid = (l + r + 1) >> 1; // ceil() not floor().
        if(ok(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        for(int i = 0; i < 3; i++) {
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
            sum[i][0] = s[i][0];
            for(int j = 1; j < len[i]; j++) sum[i][j] = sum[i][j - 1]*P + s[i][j];
        }
        printf("Case %d: %d\n", ca, BS());
    }
    return 0;
}
