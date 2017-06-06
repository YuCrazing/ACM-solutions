#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N = 5e4 + 5;
const int M = 1e5 + 5;
const int MAX = 5000;
int n, m, id[N], len[MAX], tol;
vector<ull> ha;
vector<int> inds[MAX];
ull H[N], sum[N], q[M][2];

void init() {
    srand(time(NULL)); //
    for(int i = 0; i < N; i++)
        H[i] = ull(rand())*ull(rand())*ull(rand())*ull(rand());
}

int main() {

    init();

    int x, l;
    sum[0] = tol = 0;
    memset(id, -1, sizeof(id));

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        sum[i] = sum[i - 1] + H[x];
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &l);
        ull val = 0;
        for(int j = 0; j < l; j++) {
            scanf("%d", &x);
            val = val + H[x];
        }
        q[i][0] = val;
        if(id[l] == -1) {
            len[tol] = l;
            id[l] = tol++;
        }
        inds[id[l]].push_back(i);
    }

    assert(tol < MAX);

    for(int i = 0; i < tol; i++) {
        l = len[i];
        ha.clear();
        for(int i = 1; i <= n - l + 1; i++) {
            ull t = sum[i + l - 1] - sum[i - 1];
            ha.push_back(t);
        }
        sort(ha.begin(), ha.end());
        for(int j = 0; j < inds[i].size(); j++) {
            int ind = inds[i][j];
            int a = lower_bound(ha.begin(), ha.end(), q[ind][0]) - ha.begin();
            if(a == ha.size() || ha[a] != q[ind][0]) {
                q[ind][1] = 0;
                continue;
            }
            int b = upper_bound(ha.begin(), ha.end(), q[ind][0]) - ha.begin();
            q[ind][1] = b - a;
        }
    }
    for(int i = 0; i < m; i++) printf("%llu\n", q[i][1]);


    return 0;
}
