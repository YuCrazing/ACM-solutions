#include<bits/stdc++.h>
using namespace std;

char s[222];
int vis[30]={0};

void clr(){
    for(int i = 0; i < 26; i++) vis[i]=0;
}
int sum=0;
int calc(){
    int ans=0;
    for(int i = 0; i < 26; i++) if(vis[i]) ans++;
    return ans;
}
int main(){
    int n;
    scanf("%d%s", &n, s);
    int l=-1;
    bool cl=false;
    for(int i = 0; s[i]; i++){
        if(s[i]>='A'&&s[i]<='Z'){
            sum=max(sum, calc());
            clr();
            cl=true;
        }else{
            //printf("%d\n",i);
            vis[s[i]-'a']=true;
            cl=false;
        }
    }
    if(!cl) sum=max(sum , calc());
    printf("%d\n", sum);
    return 0;
}

