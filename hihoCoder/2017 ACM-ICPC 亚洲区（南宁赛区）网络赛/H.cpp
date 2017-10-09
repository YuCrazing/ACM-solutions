#include<bits/stdc++.h>
using namespace std;

char s[40];
int cache[70], a, b, x;
bool ok(int x){
    int id=(x%(1<<6));
    x/=(1<<6);
    if(cache[id]==x) return true;
    cache[id]=x;
    return false;
}
int main(){
    a=b=0;
    for(int i = 0; i < 70; i++) cache[i]=-1;
    while(scanf("%s", s)!=EOF){
        if(s[0]=='E') break;
        sscanf(s, "%X", &x);
        //printf("x=%d\n", x);
        x/=(1<<4);
        if(ok(x)) {
            puts("Hit");
            b++;
        }else puts("Miss");
        a++;
    }

    printf("Hit ratio = %.2f%%\n", 100.0f*(1.0f*b/a) );
    return 0;
}
