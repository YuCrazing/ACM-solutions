#include<bits/stdc++.h>
using namespace std;

const int N=20*55;
const int C=32;
const int mod=1000003;
int dp[22][N][8];

void add(int &a, int b){
    a+=b;
    if(a>=mod) a-=mod;
}

int h[127], st[40];

void init(){
    int k=0;
    for(int i = 0; i < 26; i++){
        h[i+'a']=k++;
        h[i+'A']=h[i+'a'];
    }
    for(int i = 0; i < 10; i++){
        if(i==0){
            h[i+'0']=h['o'];
        }else if(i==1){
            h[i+'0']=h['i'];
        }else if(i==3){
            h[i+'0']=h['e'];
        }else if(i==5){
            h[i+'0']=h['s'];        }else if(i==7){
            h[i+'0']=h['t'];
        }
        else h[i+'0']=k++;
    }
    for(int i = 0; i < 26; i++) st[i]=((1<<0)|(1<<1));
    for(int i = 26; i < k; i++) st[i]=(1<<2);
    //for(int i = 0; i < 9; i++)st[i+26]=(1<<2);
    //st['a'-'a']=7;
    st['o'-'a']=7;
    st['i'-'a']=7;
    st['e'-'a']=7;
    st['s'-'a']=7;
    st['t'-'a']=7;
//    for(int i=0;i<k;i++){
//        printf("%d %d\n", i, st[i]);
//    }
    //printf("k=%d\n", k);
}

struct Node{
    int son[C], next;
    bool end;
};

struct AC{

    Node no[N];
    int tol;

    int newNode(){
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].end=no[tol].next=0;
        return tol++;
    }

    void init(){
        tol=0;
        newNode();
    }

    void insert(char *s){
        int cur=0;
        for(int i = 0; s[i]; i++){
            int &son=no[cur].son[h[s[i]]];
            if(!son) son=newNode();
            cur=son;
        }
        no[cur].end=true;
    }

    void build(){
        queue<int> q;
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()){
            int fa=q.front();
            q.pop();
            int nex=no[fa].next;
            if(no[nex].end) no[fa].end=true;
            for(int i = 0; i < C; i++){
                int &son=no[fa].son[i];
                if(!son){
                    son=no[nex].son[i];
                    continue;
                }
                if(no[fa].end) no[son].end=true;
                no[son].next=no[nex].son[i];
                q.push(son);
            }
        }
    }

    void debug(){
        for(int i = 0; i < tol; i++){
            printf("---\n");
            printf("no[%d].next=%d\n", i, no[i].next);
            for(int j = 0; j < C; j++){
                if(no[i].son[j]) printf("   no[%d].son[%d]=%d\n", i, j, no[i].son[j]);
            }
            printf("---\n");
        }
    }
}ac;
int n, a, b;
char s[101];
int main(){
    init();
    scanf("%d%d%d", &a, &b, &n);
    ac.init();
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        ac.insert(s);
    }
    ac.build();
    //ac.debug();
    dp[0][0][0]=1;
    for(int i = 0; i < b; i++){
        for(int j = 0; j < ac.tol; j++){
            if(ac.no[j].end) continue;
            for(int k = 0; k < 8; k++){
                if(dp[i][j][k]==0) continue;
                for(int ch = 0; ch < C; ch++){
                    int s=ac.no[j].son[ch];
                    if(ac.no[s].end) continue;
                    for(int b = 0; b < 3; b++){
                        if(st[ch]&(1<<b)){
                            add(dp[i+1][s][k|(1<<b)], dp[i][j][k]);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i = a; i <= b; i++){
        for(int j = 0; j < ac.tol; j++){
            if(ac.no[j].end) continue;
            add(ans,dp[i][j][7]);
        }
    }
    printf("%d\n", ans);

    return 0;
}
