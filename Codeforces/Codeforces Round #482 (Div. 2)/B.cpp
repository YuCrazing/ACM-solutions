#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

char s[100005];
int ct[128], mx[3];
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < 3; ++i){
        scanf("%s", &s);
        memset(ct, 0, sizeof(ct));
        int l=strlen(s);
        for(int j = 0; s[j]; ++j) ct[s[j]]++;
        mx[i]=-1;
        for(int j = 0; j < 128; ++j) if(mx[i] < ct[j]) mx[i]=ct[j];
        if(n==1){
            if(mx[i]==l) mx[i]=l-1;
            else ++mx[i];
        }else mx[i] = mx[i] + min(n, l-mx[i]);
//        printf("%d\n", mx[i]);
    }

    if(mx[0] > mx[1] && mx[0] > mx[2]){
        puts("Kuro");
    }else if(mx[1] > mx[0] && mx[1] > mx[2]){
        puts("Shiro");
    }else if(mx[2] > mx[0] && mx[2] > mx[1]){
        puts("Katie");
    }else puts("Draw");
    // (mx[0]==mx[1] || mx[0]==mx[2] || mx[1]==mx[2])
    return 0;
}
