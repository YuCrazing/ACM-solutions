#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

struct T {
    int h, m, s, ss, x, y, z;
    void read() {
        scanf("%d%d%d%2d:%2d:%2d.%3d",&x, &y, &z, &h, &m, &s, &ss);
    }
    bool operator<(const T& t)const {
        if(h==t.h && m==t.m && s==t.s) return ss < t.ss;
        if(h==t.h && m==t.m) return s < t.s;
        if(h==t.h) return m < t.m;
        return h < t.h;
    }
} ti[100005];
const int N=505;
int c[N][N], mx, cnt, id;
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; ++i) ti[i].read();
    sort(ti, ti+k);
    cnt = mx = 0;
    id=-1;
    for(int i = 0; i < k; ++i) {
        int x=ti[i].x-1;
        int y=ti[i].y-1;
        int z=ti[i].z;
        if(z==0) {
            if(c[x][y]==0) ++cnt;
            ++c[x][y];
            if(cnt >= mx) {
                mx=cnt;
                id=i;
            }
        } else {
            --c[x][y];
            if(c[x][y]==0) --cnt;
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            c[i][j]=0;
    for(int i = 0; i < k; ++i) {
        int x=ti[i].x-1;
        int y=ti[i].y-1;
        int z=ti[i].z;
        if(z==0) {
            ++c[x][y];
        } else {
            --c[x][y];
        }
        if(i==id) break;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(c[i][j]) printf("1");
            else printf("0");
        }
        puts("");
    }

    return 0;
}
