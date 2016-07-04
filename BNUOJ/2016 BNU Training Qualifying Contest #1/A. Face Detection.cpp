#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

char mp[55][55];
int s[4];
void ok(int i, int j) {
    if(mp[i][j] == 'f') s[0] ++;
    else if(mp[i][j] == 'a') s[1] ++;
    else if(mp[i][j] == 'c') s[2] ++;
    else if(mp[i][j] == 'e') s[3] ++;

}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++)
        scanf("%s", mp[i]);
    int sum = 0;
    for(int i = 0; i < n - 1; i ++)
        for(int j = 0; j < m - 1; j ++) {
            for(int k = 0; k < 4; k ++) s[k] = 0;
            ok(i, j);
            ok(i + 1, j);
            ok(i, j + 1);
            ok(i + 1, j + 1);
            int has = 1;
            for(int k = 0; k < 4; k ++)
                if(s[k] != 1) has = 0;

            sum += has;
        }
    printf("%d\n", sum);

    return 0;
}
