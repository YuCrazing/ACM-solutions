#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef double db;

int main(){
    int a[6];
    for(int i = 3; i < 6; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < 3; ++i) scanf("%d", &a[i]);
    bool ok = true;
    if(a[0] < a[3]) ok = false;
    else if(a[0] + a[1] < a[3] + a[4]) ok = false;
    else if(a[0] + a[1] + a[2] < a[3] + a[4] + a[5]) ok = false;
    puts(ok?"YES":"NO");
    return 0;
}
