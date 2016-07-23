#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define inf (~0U>>2)
#define L(x) t[x].son[0]
#define R(x) t[x].son[1]
#define lsum(x) t[t[x].son[0]].sum
#define rsum(x) t[t[x].son[1]].sum
#define N 100100
struct splaytree{
    bool rev;
	int son[2],pre,s;
	int key;
} t[N*2];
int n,m,root,tot;
int a[N];
int which(int x){return R(t[x].pre)==x;}
void sets(int pre,int x,int d){
	if(t[pre].son[d]=x) t[x].pre=pre;
}

void push_down(int x){
    if(t[x].rev) {
        swap(L(x), R(x));
        t[L(x)].rev ^= 1;
        t[R(x)].rev ^= 1;
        t[x].rev = 0;
    }
}

void push_up(int x){
	t[x].s=t[L(x)].s+t[R(x)].s+1;
}

void rot(int x){
	int pre=t[x].pre,d=which(x);
	sets(pre,t[x].son[d^1],d);
	if(t[pre].pre==0) t[x].pre=0;
	else sets(t[pre].pre,x,which(pre));
	sets(x,pre,d^1);
	push_up(pre);
}

void splay(int x,int goal){
	while(t[x].pre!=goal){
		if(t[t[x].pre].pre==goal)
			rot(x);
		else if(which(x)==which(t[x].pre))
			{rot(t[x].pre);rot(x);}
		else{rot(x);rot(x);}
	}
	push_up(x);
	if(goal==0) root=x;
}

int find(int root,int k){
	int now=root,lsize;
	while(true){
        push_down(now);
		lsize=t[L(now)].s;
		if(lsize+1==k)return now;
		if(k<=lsize) now=L(now);
		else now=R(now),k-=lsize+1;
	}
}

void build(int &x,int pre,int l,int r){
	if(l>r)return;
	int mid=l+r>>1;
	x=++tot;
	t[x].pre=pre;
	t[x].s=1;
	t[x].key = a[mid];
	build(L(x),x,l,mid-1);
	build(R(x),x,mid+1,r);
	push_up(x);
}

void reverse(int l ,int r){
    int x = find(root, l);
    int y = find(root, r + 2);
    splay(x, 0);
    splay(y, root);
    t[L(y)].rev ^= 1;
    push_up(y);
    push_up(x);
}

int ct;
void screen(int x){
	if(x==0)return;
	push_down(x);
	screen(L(x));
    a[ct ++] = t[x].key;
	screen(R(x));
}
void Debug(){
	screen(root);
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
	scanf("%d%d",&n, &m);
	int l, r;
	for(int i = 1; i <= n; ++ i) a[i] = i;

	build(root,0,0,n+1);
	while(m--){
		scanf("%d%d", &l, &r);
        reverse(l, r);
	}
	Debug();
	for(int i = 1; i < ct - 1; i ++) printf((i == ct - 2) ? "%d" : "%d ", a[i]);

return 0;
}
