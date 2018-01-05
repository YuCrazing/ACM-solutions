#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int a[N], b[N], n;

int x[10][2], ty[10];

void solve(int id, int aa) {
    x[id][aa]=aa;
    for(int i = 0; i < n; i++) {
        int k=a[i];
        k>>=(id);
        if(b[i]==0) {
            x[id][aa]=(k&x[id][aa])%2;
        } else if(b[i]==1) {
            x[id][aa]=(k|x[id][aa])%2;
        } else {
            x[id][aa]=(k^x[id][aa])%2;
        }
    }
    //printf("%d %d %d\n", id, aa, x[id][aa]);
}

void calc(int id) {
    for(int i = 0; i < 2; i++) {
        solve(id, i);
    }

    if(x[id][0]==0 && x[id][1] == 0) {
        ty[id]=0;
    } else if(x[id][0]==0 && x[id][1] == 1) {
        ty[id]=1;
    } else if(x[id][0]==1 && x[id][1] == 0) {
        ty[id]=2;
    } else {
        ty[id]=3;
    }

}
int main() {
    char op[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s%d", op, &a[i]);
        if(op[0]=='&')b[i]=0;
        else if(op[0]=='|') b[i]=1;
        else b[i]=2;
    }
    for(int i = 0; i < 10; i++) {
        calc(i);
    }

    int ans[5]= {0};

    for(int i = 0; i < 10; i++) {
        if(ty[i]==2) ans[0]|=(1<<i);
        else ans[0]|=(0<<i);
    }
    for(int i = 0; i < 10; i++) {
        if(ty[i]==0) ans[1]|=(0<<i);
        else ans[1]|=(1<<i);
    }
    for(int i = 0; i < 10; i++) {
        if(ty[i]==3) ans[2]|=(1<<i);
    }
    for(int i = 0; i < 10; i++) {
        //printf("%d %d\n", i, b[i]);
    }

    printf("3\n");
    printf("%c %d\n", '^', ans[0]);
    printf("%c %d\n", '&', ans[1]);
    printf("%c %d\n", '|', ans[2]);

    return 0;
}
