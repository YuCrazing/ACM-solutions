#include<bits/stdc++.h>
using namespace std;
int mod = 475;

bool ok(int s, int p) {
    s /= 50;
    s %= mod;
    for(int i = 0; i < 25; i++) {
        s = (s * 96 + 42) % mod;
        if(s + 26 == p) return true;
    }
    return false;
}

int main() {
    int p, x, y;
    scanf("%d%d%d", &p, &x, &y);
    int k = 0, s, ans;
    if(x < y) {
        k = (y - x + 49) / 50;
        s = k * 50 + x;
        for(int i = 0; i <= mod + 2; i++) {
            if(ok(s, p)) break;
            s += 50;
            k++;
        }
        ans = (k + 1) / 2;
    } else {
        k = (x - y) / 50;
        s = x - k * 50;
        int t = k;
        bool yes = false;
        for(int i = 0; i < t; i++) {
            if(ok(s, p)) yes=true;
            s += 50;
        }
        if(yes) ans = 0;
        else {
            s = x;
            k = 0;
            for(int i = 0; i <= mod + 2; i++) {
                if(ok(s, p)) break;
                s += 50;
                k++;
            }
            ans = (k + 1) / 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
