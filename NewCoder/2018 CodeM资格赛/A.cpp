#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m, x, a, b, c;
    double sum=0, dif1=0, dif2=0, eps=1e-8;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &x);
        sum+=a;
        if(x) dif1+=a*0.2;
    }
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &b, &c);
        if(sum > b-eps) dif2=max(dif2, c*1.0);
    }
    printf("%.2f\n", min(sum-dif1, sum-dif2));

    return 0;
}
