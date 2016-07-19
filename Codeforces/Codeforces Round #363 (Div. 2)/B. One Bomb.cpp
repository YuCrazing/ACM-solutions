#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char mp[1111][1111];
int row[1111], col[1111], sum;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n;  i++) {
        scanf("%s", mp[i]);
        for(int j = 0; j < m; j ++)
            if(mp[i][j] == '*') {
                row[i] ++;
                col[j] ++;
                sum ++;
            }
    }

    bool ok = 0;
    int x, y;
    for(int i = 0; i < n; i ++)
    for(int j = 0; j < m; j ++){
        int t = row[i] + col[j];
        if(mp[i][j] == '*') t --;
        if(t == sum){
            x = i;
            y = j;
            ok = 1;
        }
    }

    if(ok) printf("YES\n%d %d\n", x + 1, y + 1);
    else printf("NO\n");

    return 0;
}
