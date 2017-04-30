#include<bits/stdc++.h>
using namespace std;

/*
    哲学问题：找规律 or 母函数 ?
*/

const int N = 8888;
int num[3] = {1, 2, 5};
int n[3], f[N + 1];
int main() {

    while(scanf("%d%d%d", &n[0], &n[1], &n[2])) {
        if(!(n[0] || n[1] || n[2])) break;
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int k = 0; k < 3; k++) {
            for(int i = N; i >= 0; i--) {
                for(int j = 1; j <= n[k]; j ++) {
                    int t = num[k] * j;
                    if(t > N) break;
                    f[i + t] += f[i];
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < N; i++) if(!f[i]) {
                ans = i;
                break;
            }
        assert(ans != -1);
        printf("%d\n", ans);
    }
    return 0;
}
