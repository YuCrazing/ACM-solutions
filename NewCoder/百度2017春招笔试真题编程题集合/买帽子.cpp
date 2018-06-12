#include<cstdio>
#include<algorithm>
using namespace std;
 
int a[1111];
int main(){
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a[x] ++;
    }
 
    int ans = -1, ct = 0;
    for(int i = 0; i < 1000; i++){
        if(a[i]){
            ct ++;
            if(ct == 3){
                ans = i;
                break;
            }
        }
    }
 
    printf("%d\n", ans);
 
    return 0;
}