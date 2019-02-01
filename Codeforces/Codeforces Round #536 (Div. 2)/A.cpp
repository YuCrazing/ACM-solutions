#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

char c[555][555];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", c[i]);
    }
    int ct = 0;
    for(int i = 1; i < n - 1; ++i){
        for(int j = 1; j < n - 1; ++j){
            if(c[i][j] == 'X' && c[i-1][j-1] == 'X' && c[i-1][j+1] == 'X' && c[i+1][j+1] == 'X' && c[i+1][j-1] == 'X')
                ++ct;
        }
    }
    printf("%d\n", ct);
    return 0;
}
