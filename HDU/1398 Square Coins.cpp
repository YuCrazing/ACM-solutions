#include<bits/stdc++.h>
using namespace std;

const int N = 303;
const int M = 17;

int coin[M + 2], f[N];

void init() {
    for(int i = 1; i <= M; i++) coin[i] = i * i;
}

int main() {
    init();
    int n;
    while(scanf("%d", &n) && n) {
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int k = 1; k <= M; k++) {
            int num = coin[k];
            for(int i = n; i >= 0; i--) {
                for(int j = num; j + i <= n; j += num)
                    f[i + j] += f[i];
            }
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
