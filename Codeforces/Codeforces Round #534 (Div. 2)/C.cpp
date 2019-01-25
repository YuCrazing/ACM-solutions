#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

char s[1111];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    bool a = false;
    bool b = false;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            if(a) {
                puts("3 1");
                a = false;
            } else {
                puts("1 1");
                a = true;
            }
        } else {
            if(b) {
                puts("4 1");
                b = false;
            } else {
                puts("4 3");
                b = true;
            }
        }
    }
    return 0;
}
