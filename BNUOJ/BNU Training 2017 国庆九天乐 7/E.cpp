#include<bits/stdc++.h>
using namespace std;

const int N=250010;
int nex[N], las[N], mx[N], ans[N];
void kmp(char* s){
    nex[0]=nex[1]=0;
    int j=0;
    for(int i = 1; s[i]; i++){
        while(j>0&&s[i]!=s[j]) j=nex[j];
        if(s[i]==s[j])j++;
        nex[i+1]=j;
    }
    las[0]=0;
    for(int i = 0; s[i]; i++){
        int b=nex[i+1];
        las[i+1]=((2*b>=i+1)?las[b]:i+1);
    }
//    for(int i = 0; s[i]; i++){
//        printf("%d\n",las[i+1]);
//    }
    for(int i = 0; s[i]; i++){
        int j=las[i+1];
        int l=i+1;
        while(j){
            if(j+mx[j]>=i+1) {
                l=min(l, j);
                mx[j]=i+1;
            }
            if(las[j]==j) j=nex[j];
            else j=las[j];
        }
        ans[i+1]=l;
    }

    for(int i = 0; s[i]; i++){
        printf((!s[i])?"%d\n":"%d ", ans[i+1]);
    }
}
char s[N];
int main(){
    freopen("cover.in", "r", stdin);
    freopen("cover.out", "w", stdout);
    scanf("%s", s);
    kmp(s);
    return 0;
}
