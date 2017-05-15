#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 26;
int a[2][30];
string s;
char res[300010];
int pre, suf;
void check(int x) {
    if(x == 0) {
        int minn = 0;
        while(minn < N) {
            if(a[x][minn]) break;
            minn ++;
        }
        bool no = false;
        for(int i = minn + 1; i < N; i++) {
            if(a[1][i]) {
                no = true;
                break;
            }
        }
        if(no) {
            res[pre++] = 'a' + minn;
            a[x][minn]--;
        } else {
            int maxx = 25;
            while(maxx >= 0) {
                if(a[x][maxx]) break;
                maxx --;
            }
            res[suf--] = 'a' + maxx;
            a[x][maxx]--;
        }

    } else {
        int maxx = 25;
        while(maxx >= 0) {
            if(a[x][maxx]) break;
            maxx --;
        }
        bool no = false;
        for(int i = maxx - 1; i >=0; i--) {
            if(a[0][i]) {
                no = true;
                break;
            }
        }
        if(no) {
            res[pre++] = 'a' + maxx;
            a[x][maxx] --;
        } else {
            int minn = 0;
            while(minn < N) {
                if(a[x][minn]) break;
                minn ++;
            }
            res[suf--] = 'a' + minn;
            a[x][minn] --;
        }
    }
}
int main() {
    cin >> s;
    int n = s.size();
    sort(s.begin(), s.end());
    for(int i = 0; i < (n + 1) / 2; i++) a[0][s[i] - 'a'] ++;
    cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    for(int i = 0; i < n / 2; i++) a[1][s[i] - 'a'] ++;

//    for(int i = 0; i < N; i ++) printf("%d %d\n", i, a[0][i]);

    pre = 0, suf = n - 1;
    int x = 0;
    while(pre <= suf) {
        check(x);
        x = 1-x;
    }
    res[n] = 0;
    printf("%s\n", res);
    return 0;
}
