#include<bits/stdc++.h>
using namespace std;

const int MAXN=1010;
const double eps=1e-7;

struct Point {

    int x, y;

    Point(int _x=0, int _y=0):x(_x),y(_y) {};

    void read() {
        scanf("%d%d", &x, &y);
    }
    void print() {
        printf("%d %d\n", x, y);
    }
    Point operator+(const Point &t)const {
        return Point(x+t.x, y+t.y);
    }
    Point operator-(const Point &t)const {
        return Point(x-t.x, y-t.y);
    }
    int operator*(const Point &t)const {
        return x*t.x+y*t.y;
    }
    int operator^(const Point &t)const {
        return x*t.y-y*t.x;
    }

};
Point lis[MAXN];
int Stack[MAXN], top;

int dist(Point &a, Point &b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int sgn(int x) {
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
//    if(x<-eps) return -1;
//    if(x>eps) return 1;
//    return 0;
}
bool _cmp(Point p1, Point p2) {

    int tmp=(p1-lis[0])^(p2-lis[0]);
    if(sgn(tmp)>0) return true;
    else if(sgn(tmp)==0 && sgn(dist(p1, lis[0]) - dist(p2,lis[0]))<=0)
        return true;
    else return false;
}

void Graham(int n) {
    Point p0;
    int k=0;
    p0=lis[0];
    for(int i = 1; i < n; i++) {
        if((p0.y>lis[i].y) || (p0.y==lis[i].y && p0.x>lis[i].x)) {
            p0=lis[i];
            k=i;
        }
    }
    swap(lis[k], lis[0]);
    sort(lis+1, lis+n, _cmp);
    if(n==1) {
        top=1;
        Stack[0]=0;
        return;
    }
    if(n==2) {
        top=2;
        Stack[0]=0;
        Stack[1]=1;
        return ;
    }
    Stack[0]=0;
    Stack[1]=1;
    top=2;
    for(int i = 2; i < n; i++) {
        while(top>1 &&
                sgn((lis[Stack[top-1]]-lis[Stack[top-2]]) ^ (lis[i]-lis[Stack[top-2]]))<=0
             ) top--;
        Stack[top++]=i;
    }

}

int area(int a, int b, int c) {
    c=Stack[c];
    return abs((lis[c]-lis[a]) ^ (lis[b]-lis[a]));
}
int main() {
    int n, T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        //printf("t=%d %d\n", T, n);
        for(int i = 0; i < n; i++) {
            lis[i].read();
        }
        Graham(n);
//        printf("--\n");
//        for(int i = 0; i < top; i++) lis[Stack[i]].print();
//        printf("--\n");

        int mx=0;
        if(top==3) {
            mx=area(Stack[0], Stack[1], 2);
        }
        if(top>=4) {
            int cura=1, curb=3;
            for(int i = 0; i < top; i++) {
                cura=(i+1)%top;
                curb=(i+3)%top;
                for(int j=(i+2)%top; (j+1)%top !=i; j=(j+1)%top) {
                    int a=Stack[i];
                    int b=Stack[j];
                    while(area(a, b, cura) <= area(a, b, (cura+1)%top)) cura=(cura+1)%top;
                    while(area(a, b, curb) <= area(a, b, (curb+1)%top)) curb=(curb+1)%top;
                    int ta=area(a, b, cura);
                    int tb=area(a, b, curb);
                    //printf("%d %d %d %d %d %d\n", i , j, cura, curb, ta, tb);
                    if(mx < ta+tb) {
                        mx=ta+tb;
                    }
                }
            }
        }
        if(mx&1) printf("%d.5\n", mx/2);
        else printf("%d\n", mx/2);
    }
    return 0;
}

/*
3
6
0 0
3 7
10 0
11 6
0 10
10 10
5
0 0
-2 -2
3 -2
0 1
0 3
10
3 1
4 1
5 9
2 6
5 3
5 8
9 7
9 3
2 3
8 4


8 4
    10
    0 0
    1 0
    0 1
    1 1
    0 2
    1 2
    0 3
    1 3
    0 4
    1 4

*/
