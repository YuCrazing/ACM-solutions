#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

char s[2222];
int a[5222][5222], n;

set<int> st;

int get(char ch) {
    if(ch >= '0' && ch <= '9') return ch - '0';
    else return ch - 'A' + 10;
}

int check() {

    st.clear();

    int cnt = 1;
    for(int i = 2; i <= n; ++i) {
        bool same = true;
        for(int j = 1; j <= n; ++j) {
            if(a[i][j] != a[i-1][j]) {
                same = false;
                break;
            }
        }
        if(same) ++cnt;
        else {
            st.insert(cnt);
            cnt = 1;
        }
    }
    st.insert(cnt);

    int ans;

    int mi = 1e9;
    for(auto item : st) {
        mi = min(mi, item);
    }

    st.insert(n);
    for(auto item : st) {
        mi = __gcd(mi, item);
    }
    return mi;
}

int main() {
    scanf("%d", &n);
    for(int r = 1; r <= n; ++r) {
        scanf("%s", s);
        for(int i = 0; s[i]; ++i) {
            int v = get(s[i]);
            for(int j = 3; j >= 0; --j) {
                a[r][1+i*4+3-j] = ((1<<j) & v)?1:0;
            }
        }
    }

//    for(int i = 1; i <= n; ++i){
//        for(int j = 1; j <= n; ++j){
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }

    int x = check();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            swap(a[i][j], a[j][i]);
        }
    }

    int y = check();

    printf("%d\n", __gcd(x, y));

    return 0;
}
