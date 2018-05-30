#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

int main(){
    ll n;
    scanf("%I64d", &n);
    ++n;
    if(n==1) n=0;
    else if(n&1) n;
    else n/=2;
    printf("%I64d\n", n);
    return 0;
}
