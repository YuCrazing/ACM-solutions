#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 12;

ll dp[N][N][N][2];

bool isok(char ch) {
    if(ch=='?'||isdigit(ch)) return true;
    return false;
}

struct Num {

    int len, d[N];

    void init() {
        len = 0;
        memset(d, 0, sizeof(d));
    }

    int read() {
        char ch = 0;
        while(!isok(ch)) {
            if(ch==EOF)return -1;
            ch=getchar();
        }
        init();
        while(isok(ch)) {
            d[len++] = ((ch=='?') ? -1 : (ch-'0'));
            ch = getchar();
        }
        reverse(d, d+len);
        return 0;
    }

    void print() {
        for(int i = 0; i < len; i++) printf(d[i]==-1?"?":"%d", d[i]);
        printf("\n");
    }
};
Num a, b, c;

void init() {
    memset(dp, -1, sizeof(dp));
}

// position:cur, preDigx = x, preDigy = y, AddtoPreDig = one
ll dfs(int cur, int prex, int prey, bool one) {
    ll &dpp = dp[cur][prex][prey][one];
    if(dpp!=-1) return dpp;

    if(cur == a.len) {
        if(prex==0&&a.len>1) return 0; // ?????
    }
    if(cur == b.len) {
        if(prey==0&&b.len>1) return 0; // ?????
    }
    if(cur == c.len) {
        if(prex+prey+one>9) return 0;
        if((prex+prey+one)%10==0&&c.len>1) return 0; // ?????
        return 1;
    }

    dpp = 0;
    int x = ((cur>=a.len)?0:a.d[cur]);
    int y = ((cur>=b.len)?0:b.d[cur]);
    int z = c.d[cur];
    one = (one+prex+prey>9);

    vector<int> v[2];
    if(x==-1) for(int i = 0; i < 10; i++) v[0].push_back(i);
    else v[0].push_back(x);
    if(y==-1) for(int i = 0; i < 10; i++) v[1].push_back(i);
    else v[1].push_back(y);

    for(int i = 0; i < v[0].size(); i++) {
        int xx = v[0][i];
        if(z!=-1) {
            int yy = ((z>=xx+one)?(z-(xx+one)):(z+10-(xx+one)));
            if(y==-1 || y==yy) dpp += dfs(cur+1, xx, yy, one); //!!!!!
        } else {
            for(int j = 0; j < v[1].size(); j++) {
                int yy = v[1][j];
                dpp += dfs(cur+1, xx, yy, one);
            }
        }
    }

    return dpp;
}


int ca=0;
int main() {
    while(a.read()!=-1) {
        b.read();
        c.read();

//        a.print();
//        b.print();
//        c.print();

        init();

        ll ans=0;
        if(a.len <= c.len && b.len <= c.len) ans = dfs(0, 0, 0, 0);
        printf("Case %d: %lld\n", ++ca, ans);
    }
    return 0;
}
/*

11+?=12
?+11=12

*/
