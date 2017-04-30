#include<bits/stdc++.h>
using namespace std;

const int N = 52;
const int V = 52;
const int M = 102;
const int MAX = N * V * M;
int f[MAX], v[N], m[N], n;

void solve() {

    int sum = 0, mid;
    for(int i = 0; i < n; i++) sum += v[i] * m[i];
    mid = sum / 2;

    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int k = 0; k < n; k++) {
        int num = v[k];
        for(int i = mid; i >= 0; i--) {
            for(int t = 0, j = num; t < m[k] && j + i <= mid; t++, j += num) {
                f[i + j] += f[i];
            }
        }
    }

    int less = 0;
    for(int i = mid; i >= 0; i--) {
        if(f[i]) {
            less = i;
            break;
        }
    }
    printf("%d %d\n", sum - less, less);
}
int main() {
    while(scanf("%d", &n) && n >= 0) {
        for(int i = 0; i < n; i++) scanf("%d%d", &v[i], &m[i]);
        solve();
    }
    return 0;
}
