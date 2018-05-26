#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.in", "w", stdout);
    srand(time(0));
    int q, m, n, T;
    T=10;
    printf("%d\n", T);
    for(int ca = 1; ca <= T; ++ca) {
        n=rand()%30+1;
        m=rand()%(min(n, 4))+1;
        q=rand()%100+1;

        printf("%d %d %d\n", n, m, q);
        for(int i = 0; i < n; ++i) {
            printf("%c", rand()%2+'a');
        }
        puts("");
        for(int i = 0; i < m; ++i) {
            printf("%c", rand()%2+'a');
        }
        puts("");
        for(int i = 0; i < q; ++i){
            int x = rand()%(n-m+1)+1;
            int y = rand()%10000+1;
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}
