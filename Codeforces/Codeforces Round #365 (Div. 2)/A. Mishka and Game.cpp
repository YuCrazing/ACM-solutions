#include <cstdio>
using namespace std;

int main(){
    int a,b, x,y,n;
    a = b = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d%d", &x, &y);
        if(x > y) a ++;
        else if(x < y) b ++;
    }
    if(a == b) printf("Friendship is magic!^^\n");
    else if(a > b) printf("Mishka\n");
    else printf("Chris\n");
    return 0;
}
