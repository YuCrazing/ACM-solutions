#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 102;

int a[N][N], op[2][N], r[2];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    memset(op, 0, sizeof(op));
    int ans = 0;
    if(n < m) {
        for(int i = 0; i < n; i++) {
            int minn = 555;
            for(int j = 0; j < m; j++) minn = min(minn, a[i][j]);
            if(minn > 0) {
                op[0][i] = minn;
                ans += minn;
                for(int j = 0; j < m; j++) a[i][j] -= minn;
            }
        }
        for(int j = 0; j < m; j++) {
            int minn = 555;
            for(int i = 0; i < n; i++) minn = min(minn, a[i][j]);
            if(minn > 0) {
                op[1][j] = minn;
                ans += minn;
                for(int i = 0; i < n; i++) a[i][j] -= minn;
            }
        }
    } else {
        for(int j = 0; j < m; j++) {
            int minn = 555;
            for(int i = 0; i < n; i++) minn = min(minn, a[i][j]);
            if(minn > 0) {
                op[1][j] = minn;
                ans += minn;
                for(int i = 0; i < n; i++) a[i][j] -= minn;
            }
        }
        for(int i = 0; i < n; i++) {
            int minn = 555;
            for(int j = 0; j < m; j++) minn = min(minn, a[i][j]);
            if(minn > 0) {
                op[0][i] = minn;
                ans += minn;
                for(int j = 0; j < m; j++) a[i][j] -= minn;
            }
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        for(int j =0; j < m; j++) {
            if(a[i][j] != 0) {
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    if(!ok) printf("-1\n");
    else {
        printf("%d\n", ans);
        for(int i = 0; i < n; i++)
            while(op[0][i] > 0) {
                printf("row %d\n", i + 1);
                op[0][i]--;
            }
        for(int i = 0; i < m; i++)
            while(op[1][i] > 0) {
                printf("col %d\n", i + 1);
                op[1][i]--;
            }
    }

    return 0;
}
