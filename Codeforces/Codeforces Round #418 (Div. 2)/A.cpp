#include<bits/stdc++.h>
using namespace std;

int a[111], b[111];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    bool ok;
    if(m > 1) ok = 1;
    else if(m == 1) {
        for(int i = 0; i < n; i++)
            if(a[i] == 0) {
                a[i] = b[0];
                break;
            }
        bool in = true;
        int pre = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] < pre) in = false;
            pre = a[i];
        }
        if(in) ok = 0;
        else ok = 1;
    }
    if(ok) printf("Yes\n");
    else printf("No\n");
    return 0;
}
