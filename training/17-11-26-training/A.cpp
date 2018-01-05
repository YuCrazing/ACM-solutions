/*
    Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
    Mp[i]=mx>i?min(Mp[2*id-i],mx-i):l;

    抄模板的时候把 1 抄成了 l ...
*/

#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

struct Node{
    int i, ri;
    Node(int _i=0, int _ri=0):i(_i),ri(_ri){}
    bool operator<(const Node& t)const{
        return ri<t.ri;
    }
};

char Ma[N*2];
int Mp[N*2];
void Manacher(char s[], int len){
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i = 0; i < len; i++){
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0, id=0;
    for(int i = 0; i < l; i++){
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;

        if(i+Mp[i]>mx){
            mx=i+Mp[i];
            id=i;
        }
    }
}


char s[N];
int T, n, r[N], c[N];
Node a[N];

int low(int x){
    return x&(-x);
}

void add(int a, int b){
    for(int i = a; i <= n; i+=low(i)) c[i]+=b;
}

int ask(int a){
    int r=0;
    for(int i = a; i > 0; i-=low(i)) r+=c[i];
    return r;
}

void init(){
    for(int i = 1; i <= n; i++) c[i]=0;
}


int main(){
    //freopen("in.in", "r", stdin);
    scanf("%d", &T);
    while(T--){
        scanf("%s",s);
        n=strlen(s);
        Manacher(s, n);
        init();

        for(int i = 1; i <= n; i++) {
            r[i]=(Mp[i*2]-1)/2;
            //printf("%d %d\n", i, r[i]);
        }

        for(int i = 1; i <= n; i++) {
            a[i]=Node(i, r[i]+i);
            add(i, 1);
        }
        sort(a+1, a+n+1);

        int cur=1;
        long long ans=0;
        for(int i = 1; i <= n; i++){
            while(cur<=n&&a[cur].ri<i) {
                add(a[cur].i, -1);
                cur++;
            }
            ans+=ask(i-1)-ask(i-r[i]-1);
        }
        printf("%lld\n", ans);
    }
}
