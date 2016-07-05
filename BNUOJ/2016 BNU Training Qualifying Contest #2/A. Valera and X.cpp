#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

char s[311][311];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%s", s[i]);

    bool ok = 1;

    if(s[0][0] == s[0][1]) ok = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i == j || i + j == n - 1) {
                if(s[i][j] != s[0][0]) {
                    ok = 0;
                    break;
                }
            } else {
                if(s[i][j] != s[0][1]) {
                    ok = 0;
                    break;
                }
            }
        }
        if(!ok) break;
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
