#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

int n;
char a[333];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", a);
        if(n==2 && a[1] <= a[0]) printf("NO\n");
        else {
            printf("YES\n2\n%c ", a[0]);
            for(int i = 1; i < n; ++i) printf("%c", a[i]);
            puts("");
        }
    }
    return 0;
}
