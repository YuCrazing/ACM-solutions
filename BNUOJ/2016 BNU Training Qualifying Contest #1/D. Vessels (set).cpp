#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 10;
set<int> st;
int a[MAXN], b[MAXN];
int main() {
    int n, m, op, p, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        st.insert(i);
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i ++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &p, &x);
            int nxt;
            set<int>::iterator it = st.lower_bound(p);
//            set<int>::iterator it = lower_bound(st.begin(), st.end(), p); // TLE
            if(it == st.end()) continue;
            nxt = *it;
            for(int j = nxt; j <= n; j ++) {
                if(a[j] <= x) {
                    x -= a[j];
                    a[j] = 0;
                    st.erase(j);
                } else {
                    a[j] -= x;
                    x = 0;
                }
                if(x == 0) break;
            }
        } else {
            scanf("%d", &x);
            printf("%d\n", b[x] - a[x]);
        }
    }
    return 0;
}
