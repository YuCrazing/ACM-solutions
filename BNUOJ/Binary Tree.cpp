#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 21092013;
const int MAXN = 111111;
char s[2][MAXN];
char p[MAXN];
int remap[MAXN], upos[MAXN];

int top1, top2;
struct Nxt {
    int l, r;
} unxt[MAXN];
struct Char {
    int pos, nxt, mul;
    char ch;

    Char() {};
    Char(int _pos, char _ch):pos(_pos),ch(_ch) {};
} cha[MAXN];

void init() {
    top1 = top2 = -1;
}


int main() {
//    freopen("data.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        init();
        scanf("%s", s[0]);
        scanf("%s", s[1]);
        int l1 = strlen(s[0]);
        for(int i = 0; i < l1; i ++) {
            if(s[0][i] != 'U') p[++top1] = s[0][i];
            else if(s[0][i] == 'U') {
                if(top1 == -1) continue;
                else top1 --;
            }
        }

        int l2 = strlen(s[1]);
        int l, r, ucnt = 0;
        l = r = l2;
        for(int i = l2 - 1; i > -1; i --) {
            if(s[1][i] == 'U') {
                unxt[i].l = l;
                unxt[i].r = r;
            } else if(s[1][i] == 'L') l = i;
            else r = i;
        }

        for(int i = 0; i < l2; i ++) {
            if(s[1][i] != 'U') {
                cha[++top2] = Char(i, s[1][i]);
                remap[i] = top2;
            } else upos[ucnt ++] = i;
        }

        l = r = top2 + 1;
        for(int i = top2; i > -1; i --) {
            if(cha[i].ch == 'L') {
                cha[i].nxt = l;
                l = i;
            } else {
                cha[i].nxt = r;
                r = i;
            }
        }

        cha[top2 + 1].mul = 0;
        for(int i = top2; i > -1; i --) {
            if(cha[i].nxt == top2 + 1) cha[i].mul = (2 * cha[i + 1].mul % MOD + 1) % MOD;
            else cha[i].mul = ((2 * cha[i + 1].mul % MOD - cha[cha[i].nxt + 1].mul) % MOD + MOD) % MOD; // Be careful subtract
        }

        ucnt = min(top1 + 1, ucnt);
        int res = 1;
        if(top2 > -1) res = (cha[0].mul + res) % MOD;
        for(int i = 0; i < ucnt; i ++) {
            int index = top1 + 1 - ucnt + i, nxt;
            if(p[top1 - i] == 'L') nxt = unxt[upos[i]].r;
            else nxt = unxt[upos[i]].l;
            if(nxt < l2){
                res  = (res + cha[remap[nxt] + 1].mul) % MOD;
                res = (res + 1) % MOD;
            }
            res = (res + 1) % MOD;
        }
        printf("Case %d: %d\n", cas, res);
    }
    return 0;
}

/*

2
L
LU
L
L

10
LULR
LULULURURR
L
UR
L
U
L
UUUUUU
UUUUU
UUUUU

*/
