#include<bits/stdc++.h>
using namespace std;

const int N=220;

char mp[N][N], s[N*N];

struct Node {
    int x, y;
    Node(int _x=0, int _y=0):x(_x),y(_y) {}
    Node operator+(const Node& t)const {
        return Node(x+t.x, y+t.y);
    }
};

Node src, mx, mi, pos;
int d;

Node dir[4]= {
    Node(0, 1),
    Node(1, 0),
    Node(0, -1),
    Node(-1, 0)
};

void init() {
    src=Node(N/2, N/2);
    mx=Node(N/2, N/2);
    mi=Node(N/2, N/2);
    pos=src;
    d=0;
    memset(mp, '#', sizeof(mp));
    mp[pos.x][pos.y]='.';
}

void mov() {
    pos=pos+dir[d];
    mp[pos.x][pos.y]='.';
    mx.x=max(mx.x, pos.x);
    mx.y=max(mx.y, pos.y);
    mi.x=min(mi.x, pos.x);
    mi.y=min(mi.y, pos.y);
}

void rot() {
    d=(d+1)%4;
}

void proc(char ch) {
    if(ch=='R') {
        rot();
        mov();
    } else if(ch=='F') {
        mov();
    } else if(ch=='L') {
        rot();
        rot();
        rot();
        mov();
    } else if(ch=='B') {
        rot();
        rot();
        mov();
    }
}

int T;
int main() {
    scanf("%d", &T);
    printf("%d\n", T);
    while(T--) {
        init();
        scanf("%s", s);
        for(int i = 0; s[i]; i++) {
            proc(s[i]);
        }
        printf("%d %d\n", mx.x+1-mi.x-1+1, mx.y+1-mi.y+1);
        for(int i = mi.x-1; i <= mx.x+1; i++)
            for(int j = mi.y; j <= mx.y+1; j++)
                printf(j==mx.y+1?"%c\n":"%c", mp[i][j]);
    }
    return 0;
}
