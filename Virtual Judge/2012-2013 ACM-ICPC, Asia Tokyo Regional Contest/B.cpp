#include<cstdio>
using namespace std;

int a[12][4], tol, res[20*20*20][3], ans[12];
char code[100];
int n, m, r, c, s;

void add(char ch) {
    switch (ch) {
    case '(':
        r++;
        break;
    case ')':
        r--;
        break;
    case '{':
        c++;
        break;
    case '}':
        c--;
        break;
    case '[':
        s++;
        break;
    case ']':
        s--;
        break;
    }
}

bool check(int x, int y, int z) {
    for(int i = 0; i < n-1; i++) {
        if(a[i][0]*x+a[i][1]*y+a[i][2]*z!=a[i][3]) return false;
    }
    return true;
}

void solve() {
    tol = 0;
    for(int x = 1; x <= 20; x++) {
        for(int y = 1; y <= 20; y++) {
            for(int z = 1; z <= 20; z++) {
                if(check(x, y, z)) {
                    res[tol][0] = x;
                    res[tol][1] = y;
                    res[tol][2] = z;
                    tol++;
                }
            }
        }
    }
}

int same() {
    if(tol==0) return -1;
    int sum = res[0][0]*r+res[0][1]*c+res[0][2]*s;
    for(int i = 1; i < tol; i++) {
        if(res[i][0]*r+res[i][1]*c+res[i][2]*s!=sum) return -1;
    }
    return sum;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        if(!n&&!m) break;
        gets(code);
        r = c = s = 0;
        for(int i = 0; i < n; i++) {
            gets(code);
            if(i) {
                int j=0;
                while(code[j]=='.') j++;
                a[i-1][0]=r;
                a[i-1][1]=c;
                a[i-1][2]=s;
                a[i-1][3]=j;
            }
            for(int j = 0; code[j]; j++) {
                add(code[j]);
            }
        }
        solve();
        r = c = s = ans[0] = 0;
        for(int i = 0; i < m; i++) {
            gets(code);
            if(i) {
                ans[i] = same();
            }
            for(int j = 0; code[j]; j++) {
                add(code[j]);
            }
        }
        for(int i = 0; i < m; i++) {
            printf(i==m-1?"%d\n":"%d ", ans[i]);
        }
    }
    return 0;
}
