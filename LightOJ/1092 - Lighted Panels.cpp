#include<bits/stdc++.h>
using namespace std;

const int N = 66;
int n, m, nm, ans, T, a[N][N], x[N];
int d[3] = {-1, 0, 1};
char s[10][10];
vector<int> freeVar;
bool isfree[N];

bool ok(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void init() {
    nm = n*m;
    ans = 1e9;
    freeVar.clear();
    memset(a, 0, sizeof(a));
    memset(isfree, 0, sizeof(isfree));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int id = i * m + j, sta;
            sta = (s[i][j] == '*') ? 1 : 0;

            for(int x = 0; x < 3; x++)
                for(int y = 0; y < 3; y++) {
                    if(ok(i + d[x], j + d[y])) a[id][(i+d[x])*m + (j+d[y])] = 1;
                }

            a[id][nm] = sta^1;
        }
}

void swapLine(int x, int y) {
    for(int i = 0; i <= nm; i++) swap(a[x][i], a[y][i]);
}

bool Gauss() {

    init();

    int freeNum = 0;

    for(int k = 0; k < nm; k++) {
        int id = -1;
        for(int i = k; i < nm; i++)
            if(a[i][k]) {
                id = i;
                break;
            }

        if(id == -1) {
            freeVar.push_back(k);
            isfree[k] = true;
            freeNum ++;
            assert(freeNum < 20); // ??
            continue;
        }

        swapLine(k, id);

        for(int i = 0; i < nm; i++)
            if(i != k && a[i][k]) {
                for(int j = k; j <= nm; j++) a[i][j] ^= a[k][j];
            }
    }

    /* Check invalid equation */
    for(int i = nm - 1; i >= 0; i--) {
        bool no = true;
        for(int j = 0; j < nm; j++) {
            if(a[i][j]) no = false;
        }
        if(no && a[i][nm]) return false;
    }

    return true;
}

void check() {

    /* Clear x[] value. Important! */
    for(int i = 0; i < nm; i++) if(!isfree[i]) x[i] = -1; //!!!!

    for(int i = nm - 1; i >= 0; i--) {
        int id = -1, b = a[i][nm];
        for(int j = i; j < nm; j++) {
            if(a[i][j]) {
                if(x[j] == -1) {
                    if(id != -1) {
                        assert(0); //
                    }
                    id = j;
                } else {
                    b ^= x[j];
                }
            }
        }
        if(id == -1) continue;
        x[id] = b;
    }

    int sum = 0;
    for(int i = 0; i < nm; i++) {
        assert(x[i] != -1);
        sum += x[i];
    }
    ans = min(ans, sum);
}

void dfs(int cur) {
    if(cur >= freeVar.size()) {
        check();
        return ;
    }
    x[freeVar[cur]] = 0;
    dfs(cur + 1);
    x[freeVar[cur]] = 1;
    dfs(cur + 1);
}



int main() {

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%s", s[i]);

        printf("Case %d: ", ca);
        if(!Gauss()) printf("impossible\n");
        else {
            dfs(0);
            printf("%d\n", ans);
        }

    }
    return 0;
}
/*

*/
