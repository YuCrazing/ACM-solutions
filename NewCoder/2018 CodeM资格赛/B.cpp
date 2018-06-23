#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m, k, id=-1;
    long long mx = -1e9, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; ++i){
        scanf("%lld%lld", &a, &b);
        if(mx <= a*m + b*(n-m)){
            mx = a*m + b*(n-m);
            id=i;
        }
    }
    for(int i = 0; i < id; ++i) printf(i==k-1?"0":"0 ");
    if(id != k-1){
        printf("%d ", n);
        for(int i = id+1; i < k; ++i) printf(i==k-1?"0":"0 ");
    }else{
        printf("%d", n);
    }

    return 0;
}

