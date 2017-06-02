#include<bits/stdc++.h>
using namespace std;

int a[4][4];
int main() {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
    bool ok = 0;
    for(int i = 0; i < 4; i++) {
        if(a[i][3] == 1 && (a[i][1] || a[i][2] || a[i][0])) {
            ok = 1;
            break;
        }
        if(a[i][3] == 1) {
            for(int j = 1; j < 4; j++) if(a[(i + j)%4][(3 + j)%4]) {
                    ok = 1;
                    break;
                }
        }
        if(ok) break;
    }
    printf(ok ? "YES\n" : "NO\n");
    return 0;
}
