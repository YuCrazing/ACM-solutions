#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, m, reh;
    scanf("%d:%d", &h, &m);
    reh = h%10*10+h/10;
    int ans = 0;

    if(m <= reh) {
        if(reh >= 60) {
            ans = 60 - m;
            h++;
            for(; ; h++) {
                h = h % 24;
                reh = h%10*10+h/10;
                if(reh < 60) {
                    ans += reh;
                    break;
                }
                ans += 60;
            }
        } else ans = reh - m;
    } else {
        ans = 60 - m;
        h = (h + 1) % 24;
        for(; ; h++) {
            h = h % 24;
            reh = h%10*10+h/10;
            if(reh < 60) {
                ans += reh;
                break;
            }
            ans += 60;
        }
    }
    printf("%d\n", ans);

    return 0;
}
