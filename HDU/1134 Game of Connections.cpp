#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int D = 80;
const int N = 202;

struct Num {
    int len;
    char s[D];

    Num() {
        memset(s, '0', sizeof(s));
    };

    Num(int n) {
        len = 0;
        while(n > 0) {
            s[len++] = n % 10 + '0';
            n /= 10;
        }
        if(!len) s[len++] = '0';
    }

    Num(char* ss) {
        len = strlen(ss);
        for(int i = 0; i < len; i++) s[i] = ss[len - i - 1];
    }

    Num operator+(const Num& b) const {
        Num c;
        int lmax = max(len, b.len), lmin = min(len, b.len), t, add = 0, mark = 0;
        if(len > b.len) mark = 1;
        for(int i = 0; i < lmax; i++) {
            if(i < lmin)  t = s[i] - '0' + b.s[i] - '0' + add;
            else {
                if(mark) t = s[i] - '0' + add;
                else t = b.s[i] - '0' + add;
            }
            if(t > 9) {
                t -= 10;
                add = 1;    // add =
            } else add = 0;
            c.s[i] = t + '0';
        }
        if(add) {
            c.s[lmax] = add + '0';
            c.len = lmax + 1;
        } else c.len = lmax;

        return c;
    }

    Num operator*(const Num& b) const {
        Num c;
        int add, t, l;
        for(int i = 0; i < len; i++) {
            add = 0; // !!!
            for(int j = 0; j < b.len; j++) {
                int t = (s[i] - '0') * (b.s[j] - '0') + add;
                if(t > 9) {
                    add = t / 10;
                    t %= 10;
                } else add = 0;

                t += c.s[i + j] - '0';
                if(t > 9) {
                    t -= 10;
                    add ++;
                }
                c.s[i + j] = t + '0';
            }
            l = i + b.len;
            if(add) { // !!!
                c.s[l] = add + '0';
                c.len = l + 1;
            } else c.len = l;
        }
        return c;
    }

    void print() const {
        for(int i = len - 1; i >= 0; i--)
            printf(i ? "%c" : "%c\n", s[i]);
    }
};

bool has[N];
Num c[N];

Num dfs(int n) {
    if(n <= 1) return Num(1);
    if(has[n]) return c[n];
    has[n] = 1;
    c[n] = Num(0);
    for(int i = 0; i < n; i++) c[n] = c[n] + dfs(i) * dfs(n - 1 - i);
    return c[n];
}
int main() {
//    for(int i = 0; i < 111; i++) dfs(i).print();
    int n;
    while(scanf("%d", &n) && n >= 0) {
        dfs(n).print();
    }
    return 0;
}
