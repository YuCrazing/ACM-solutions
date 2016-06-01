#include <cstdio>
#include <algorithm>
using namespace std;

struct Time {
    int h, m, s, p, q;

    Time() {}

    Time(int _h, int _m, int _s):h(_h), m(_m), s(_s) {
        p = 0;
        q = -1;
    }

    Time(int _h, int _m, int _s, int _p, int _q):h(_h), m(_m), s(_s), p(_p), q(_q) {}

    void show() {
        if(p == 0) printf("%02d:%02d:%02d\n",h, m, s);
        else printf("%02d:%02d:%02d %d/%d\n",h, m, s, p, q);
    }

    bool operator<=(const Time& b)const {
        if(h == b.h && m == b.m) return s + 1.0 * p / q <= b.s + 1.0 * b.p / b.q;
        else if(h == b.h) return m <= b.m;
        return h <= b.h;
    }

    bool operator==(const Time& b)const {
        if(p == 0 && b.p == 0) return h == b.h && m == b.m && s == b.s;
        return h == b.h && m == b.m && s == b.s && p == b.p && q == b.q;
        return false;
    }

    bool isValid() {
        if(p == 0) return  s < 60 && s > -1;
        return s + 1.0 * p / q < 60 && s + 1.0 * p / q >= 0;
    }
};

Time res[1500];

int main() {
    int T, h, m, s, cnt;
    Time a, b, sym, ans;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {

        scanf("%d:%d:%d", &h, &m, &s);
        sym = Time(h, m, s);
        scanf("%d:%d:%d", &h, &m, &s);
        a = Time(h, m, s);
        scanf("%d:%d:%d", &h, &m, &s);
        b = Time(h, m, s);

        cnt = 0;
        for(h = a.h; h <= b.h; h ++) {
            for(m = 0; m < 60; m ++) {
                int tmp = 2 * (3600 * sym.h + 60 * sym.m + sym.s) - (3600 * h + 780 * m);
                if(tmp % 13 == 0) ans = Time(h, m, tmp/13);
                else ans = Time(h, m, tmp/13, tmp%13, 13);
                if(ans.isValid() && a <= ans && ans <= b) res[cnt++] = ans;

                tmp = 2 * (3600 * ((sym.h + 6)%12)  + 60 * sym.m + sym.s) - (3600 * h + 780 * m);
                if(tmp % 13 == 0) ans = Time(h, m, tmp/13);
                else ans = Time(h, m, tmp/13, tmp%13, 13);
                if(cnt > 0 && ans == res[cnt-1]) continue;
                if(ans.isValid() && a <= ans && ans <= b) res[cnt++] = ans;
            }
        }

        printf("Case %d: %d\n", cas, cnt);
        for(int i = 0; i < cnt; i ++) res[i].show();
    }
    return 0;
}

/*
solution:
    (h + m/60 + s/3600)/12 + (m + s/60)/60 = 2 * ((sym.h + sym.m/60 +sym.s/3600) / 12).
    symmetry line can be sym or (sym + 6hours)%12.

sample input:
    10
    06:00:00 00:00:00 11:59:59
*/
