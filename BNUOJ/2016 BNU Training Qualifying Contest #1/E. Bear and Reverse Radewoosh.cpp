#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Node {
    int p, t;
} p[55];
int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i ++) scanf("%d",&p[i].p);
    for(int i = 0; i < n; i ++) scanf("%d",&p[i].t);
    int t = 0, a = 0, b = 0;
    for(int i = 0 ; i < n; i ++) {
        t += p[i].t;
        a += max(0, p[i].p - c * t);
    }

    t = 0;
    for(int i = n - 1; i > -1;  i--) {
        t += p[i].t;
        b += max(0, p[i].p - c * t);
    }
    if(a > b) printf("Limak\n");
    else if(a < b) printf("Radewoosh\n");
    else printf("Tie\n");

    return 0;
}
