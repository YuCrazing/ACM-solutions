#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q1;//top is small
priority_queue<int, vector<int>, less<int> > q2;//top is big

int tol;

void init() {
    tol=0;
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
}

void insert(int x) {
    tol++;
    if(q2.empty()) {
        q2.push(x);
        return ;
    }
    if(x<=q2.top()) {
        if(!(tol&1)) {
            q1.push(q2.top());
            q2.pop();
        }
        q2.push(x);
    } else {
        q1.push(x);//!!
        if(tol&1) {
            q2.push(q1.top());
            q1.pop();
        }
    }
}

void delet() {
    tol--;
    q2.pop();
    if(tol&1) {
        q2.push(q1.top());
        q1.pop();
    }
}

void ask() {
    printf("%d\n", q2.top());
}

int n, x, T;
char op[10];
int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        while(n--) {
            scanf("%s", op);
            if(op[0]=='I') {
                scanf("%d", &x);
                insert(x);
            } else if(op[0]=='Q') ask();
            else delet();
        }
    }
    return 0;
}
