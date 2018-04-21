#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("in.in", "w", stdout);
    srand(time(0));
    int T = 30;
    int n = 200;
    printf("%d\n", T);
    for(int ca = 1; ca <= T; ca++) {
        printf("%d\n", n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d", rand()%2);
            }
            printf("\n");
        }
    }
}
