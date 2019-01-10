#include<bits/stdc++.h>
using namespace std;

int a[9], b[9];
char s[20];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", s);
        if(!strcmp(s, "M")) ++a[4];
        else if(!strcmp(s, "L")) ++a[0];
        else if(!strcmp(s, "XL")) ++a[1];
        else if(!strcmp(s, "XXL")) ++a[2];
        else if(!strcmp(s, "XXXL")) ++a[3];
        else if(!strcmp(s, "S")) ++a[5];
        else if(!strcmp(s, "XS")) ++a[6];
        else if(!strcmp(s, "XXS")) ++a[7];
        else if(!strcmp(s, "XXXS")) ++a[8];
    }
    for(int i = 0; i < n; ++i){
        scanf("%s", s);
        if(!strcmp(s, "M")) ++b[4];
        else if(!strcmp(s, "L")) ++b[0];
        else if(!strcmp(s, "XL")) ++b[1];
        else if(!strcmp(s, "XXL")) ++b[2];
        else if(!strcmp(s, "XXXL")) ++b[3];
        else if(!strcmp(s, "S")) ++b[5];
        else if(!strcmp(s, "XS")) ++b[6];
        else if(!strcmp(s, "XXS")) ++b[7];
        else if(!strcmp(s, "XXXS")) ++b[8];
    }
    for(int i = 0; i < 9; ++i){
        int mi=min(a[i], b[i]);
        a[i] -= mi;
        b[i] -= mi;
    }
    int ans=0;
    for(int i = 0; i < 9; ++i) ans += a[i];
    printf("%d\n", ans);
    return 0;
}
