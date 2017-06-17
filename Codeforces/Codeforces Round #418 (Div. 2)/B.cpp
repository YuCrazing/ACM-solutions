#include<bits/stdc++.h>
using namespace std;

int a[1111], b[1111], c[1111], n, p[4], pos[4];
bool vis[1111];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    int tol = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            p[0 + tol] = a[i];
            pos[0 + tol] = i;
            p[1 + tol] = b[i];
            pos[1 + tol] = i;
            tol += 2;
        } else {
            vis[a[i]] = 1;
            c[i] = a[i];
        }
    }
    int x, y;
    if(tol == 2) {
        for(int i = 1; i <= n; i++) if(!vis[i]) {
                x = i;
                break;
            }
        c[pos[0]] = x;
    } else {
        if(vis[p[0]] == 0 && vis[p[3]] == 0) {
            x = p[0];
            y = p[3];
        } else if(vis[p[1]] == 0 && vis[p[2]] == 0) {
            x = p[1];
            y = p[2];
        }
        c[pos[0]] = x;
        c[pos[3]] = y;
    }
//    for(int i = 1; i <= n; i++) printf("%d: %d\n", i, vis[i]);

    for(int i = 0; i < n; i++) printf((i == n - 1) ? "%d\n" : "%d ", c[i]);
    return 0;
}
