#include<bits/stdc++.h>
using namespace std;
/*
    a[i][0]: Numbers of'[' at position i.
    a[i][1]: Numbers of']' at position i.
*/
const int N = 1e6 + 5;
int a[N][2], n;
int main() {
    while(scanf("%d", &n) != EOF) {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            a[l][0]++;
            a[r][1]++;
        }

        int l, cnt = 0;
        for(int i = 0; i < N; i++) {
            if(a[i][0]) { // '[' at i.
                if(!cnt) l = i;
                cnt += a[i][0];
            }
            if(a[i][1]) { // ']' at i.
                cnt -= a[i][1];
                if(!cnt) printf("%d %d\n", l, i);
            }
        }
    }
    return 0;
}
