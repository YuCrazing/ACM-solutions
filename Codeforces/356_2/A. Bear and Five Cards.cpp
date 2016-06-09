#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a[111], b[10], sum = 0;
    for(int i = 0; i < 111; i ++) a[i] = 0;
    for(int i = 0; i < 5; i ++) {
        scanf("%d", &b[i]);
        a[b[i]] ++;
        sum += b[i];
    }

    int maxx = 0;
    for(int i = 0; i < 5; i ++){
        if(a[b[i]] >= 2){
            maxx = max(maxx, 2*b[i]);
        }
        if(a[b[i]] >= 3){
            maxx = max(maxx, 3*b[i]);
        }
    }
    printf("%d\n", sum - maxx);
}
