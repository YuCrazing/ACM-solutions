#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s, d, las;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &s, &d);
        if(!i){
            las=s;
        }else{
            las++;
            int k=(las-s+d-1)/d;
            k=max(k, 0);
            las=k*d+s;
        }
    }
    printf("%d\n", las);
    return 0;
}
