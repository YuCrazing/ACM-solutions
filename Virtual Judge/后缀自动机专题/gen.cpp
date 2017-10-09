#include<bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    freopen("in.in", "w", stdout);
    int n=1;
    int l=1e3;
    int k=1;
    //printf("%d\n", k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < l; j++) {
            printf("%c", 'a');
            //printf("%c", 'a'+rand()%5);
        }
        printf("\n");
    }
    printf("#\n");
    return 0;
}
