#include<bits/stdc++.h>
using namespace std;

const int N=100;
int a[N], b[N], bb[N];

void proc(int n){
    int k=0;
    for(int i = 1; i <= n; i++) if(a[i]!=i) b[++k]=a[i];
    for(int i = 1; i <= k; i++) bb[i]=b[i];
    sort(bb+1, bb+k+1);
    for(int i = 1; i <= k; i++) b[i]=lower_bound(bb+1, bb+k+1, b[i])-bb;
    printf("(");
    for(int i = 1; i <= k; i++) printf("%d ",b[i]);
    printf(")");

}

void get(int n){
    for(int i = 1; i <= n; i++) a[i]=i;
    do{
        int cnt=0;
        bool ok=true;
        for(int i = 1; i <= n; i++){
            if(a[i]==i) cnt++;
        }
        for(int i = 1; i < n; i++){
            if(((i&1)==0)&&(a[i]>a[i-1] || a[i]>a[i+1])){
                ok=false;
                break;
            }
        }
        if(a[n]>a[n-1])ok=false;
        if(cnt!=n/2)ok=false;
        if(ok){
            printf("(");
            for(int i = 1; i <= n; i++) printf("%d ", a[i]);
            printf(")");
            proc(n);
            puts("");

        }

    }while(next_permutation(a+1, a+1+n));
}
int main(){
    for(int i = 2; i < 10; i+=2){
        printf("i=%d\n",i);
        get(i);
    }
    return 0;
}
