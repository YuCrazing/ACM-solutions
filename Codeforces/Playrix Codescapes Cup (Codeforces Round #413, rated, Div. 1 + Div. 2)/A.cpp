#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, t, k, d;
    scanf("%d%d%d%d", &n, &t, &k, &d);
    int t1 = (n + k - 1) / k * t;
    int t2 = d + t;
    if(t2 / t * k >= n) printf("NO\n");
    else printf("YES\n");
    return 0;
}
