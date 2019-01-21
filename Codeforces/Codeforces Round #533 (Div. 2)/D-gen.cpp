#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("in.in", "w", stdout);
    int n, m, p;
    n = 1000;
    m = 1000;
    p = 1;
    printf("%d %d %d\n", n, m, p);
    printf("%d\n", 1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(i==0&&j==0) putchar('1');
            else putchar('.');
        }
        puts("");
    }
}
