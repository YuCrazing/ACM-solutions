#include <cstdio>
using namespace std;
typedef long long ll;

char mp[5][5];
bool ok(int i, int j) {
    if(i < 0 || i > 2 || j < 0 || j > 2) return false;
    if(mp[i][j] == mp[i][j + 1] && mp[i][j] == mp[i + 1][j + 1] && mp[i][j] == mp[i + 1][j]) return true;
    return false;
}

int main() {
    for(int i = 0; i < 4; i ++) scanf("%s", mp[i]);
    bool can = false;
    for(int i = 0; i < 4; i ++) {
        for(int j = 0;  j < 4; j ++) {
            if(mp[i][j] == '#') {
                if(ok(i,j) || ok(i - 1, j - 1) || ok(i - 1, j) || ok(i, j - 1)) can = true;
                mp[i][j] = '.';
                if(ok(i,j) || ok(i - 1, j - 1) || ok(i - 1, j) || ok(i, j - 1)) can = true;
                mp[i][j] = '#';
            } else {
                if(ok(i,j) || ok(i - 1, j - 1) || ok(i - 1, j) || ok(i, j - 1)) can = true;
                mp[i][j] = '#';
                if(ok(i,j) || ok(i - 1, j - 1) || ok(i - 1, j) || ok(i, j - 1)) can = true;
                mp[i][j] = '.';
            }
            if(can) break;
        }
        if(can) break;
    }
    if(can) printf("YES\n");
    else printf("NO\n");
    return 0;
}
