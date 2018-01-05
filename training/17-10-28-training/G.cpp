#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e5+10;
const int N=26;
char s[MAXN], t[MAXN];
ll ans;
struct PAM{

    int next[MAXN][N];
    int fail[MAXN];
    int cnt[MAXN];
    int num[MAXN];
    int len[MAXN];
    int S[MAXN];
    int last;
    int n;
    int p;
    int newnode(int l){
        for(int i = 0; i < N; i++) next[p][i]=0;
        cnt[p]=num[p]=0;
        len[p]=l;
        return p++;
    }
    void init(){
        p=0;
        newnode(0);
        newnode(-1);
        last=0;
        n=0;
        S[n]=-1;
        fail[0]=1;
    }
    int get_fail(int x){
        while(S[n-len[x]-1]!=S[n]) x=fail[x];
        return x;
    }
    void add(int c){
        c-='a';
        S[++n]=c;
        int cur=get_fail(last);
        if(!next[cur][c]){
            int now=newnode(len[cur]+2);
            fail[now]=next[get_fail(fail[cur])][c];
            next[cur][c]=now;
            num[now]=num[fail[now]]+1;
        }
        last=next[cur][c];
        cnt[last]++;
    }
    void count(){
        for(int i = p-1; i >= 0; i--) cnt[fail[i]]+=cnt[i];
    }
}tree1, tree2;

void dfs(int x,int y){
    for(int i = 0; i < N; i++){
        int xx=tree1.next[x][i];
        int yy=tree2.next[y][i];
        if(xx&&yy){
            ans+=1LL*tree1.cnt[xx]*tree2.cnt[yy];
            dfs(xx, yy);
        }
    }
}

int main(){
    int sk;
    scanf("%d", &sk);
    for(int cas=1; cas<=sk; cas++){
        scanf("%s%s", s, t);
        int n=strlen(s);
        int m=strlen(t);
        tree1.init();
        tree2.init();
        for(int i = 0; i < n; i++) tree1.add(s[i]);
        for(int i = 0; i < m; i++) tree2.add(t[i]);
        tree1.count();
        tree2.count();
        ans=0;
        dfs(0, 0);
        dfs(1, 1);
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
