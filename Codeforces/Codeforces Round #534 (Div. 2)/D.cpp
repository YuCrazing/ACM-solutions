#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
char s[111];
int p[50];

char ask(int x,int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    scanf("%s", s);
    return s[0];
}

void print(int x) {
    printf("! %d\n", x);
    fflush(stdout);
}

int main() {

    while(1) {
        scanf("%s", s);
        if(strcmp(s, "mistake") == 0 || strcmp(s, "end") == 0) break;

        if(ask(0, 1) == 'x') {
            print(1);
            continue;
        }

        int P = 30;
        p[0] = 1;
        for(int i = 1; i <= P; ++i) p[i] = p[i-1] * 2;

        int k = 0;
        for(int i = 0; i < P; ++i) {
            if(ask(p[i], p[i+1]) == 'x') {
                k = i;
                break;
            }
        }

        int l = p[k]+1, r = p[k+1];
        while(l < r) {
            int mid = (l+r)/2;
            if(ask(p[k], mid) == 'x') r = mid;
            else l = mid+1;
        }
        print(l);

    }
    return 0;
}
