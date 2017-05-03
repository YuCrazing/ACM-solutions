#include<bits/stdc++.h>
using namespace std;

const int N = 402;
struct Num {
    char s[N];
    int len;

    Num() {
        len = 1;
        memset(s, '0', sizeof(s));
    };
    Num(char *ss) {
        len = strlen(ss);
        for(int i = len - 1; i >= 0; i--) {
            s[len - 1 - i] = ss[i];
        }
        s[len] = '0';
    }

    Num operator-(const Num& b)const {
        Num c;
        int sub = 0;
        for(int i = 0; i < len; i++) {
            int up = s[i] - '0';
            int down = (i >= b.len) ? 0 : (b.s[i] - '0');
            if(up >= down + sub) {
                c.s[i] = up - down - sub + '0';
                sub = 0;
            } else {
                c.s[i] = up - down - sub + '0' + 10;
                sub = 1;
            }
//            printf("i = %d, up = %d down = %d, sub = %d\n", i, up, down, sub);
        }
        for(int i = len - 1; i >=0; i--) if(c.s[i] != '0') {
                c.len = i + 1;
                break;
            }
        return c;
    }

    void print() const {
        for(int i = len - 1; i >= 0; i--)
            printf(i ? "%c" : "%c\n", s[i]);
    }
};

char a[N], b[N];
int main() {
    while(scanf("%s%s", &a, &b) != EOF) {
        Num x(a), y(b);
        (x - y).print();
    }
    return 0;
}
