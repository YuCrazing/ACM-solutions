/*
    先判断状态t与s是不是完全相同
    若不完全相同再判断是否满足t.a+t.b-1==t.c
    满足条件则从t往前推导状态，判断是否t.a,t.b与s中两个数相同
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {

    int a, b, c;

    Node(int _a = 0, int _b = 0, int _c = 0):a(_a),b(_b),c(_c) {}

    bool operator==(const Node& t)const {
        return t.a==a&&t.b==b&&t.c==c;
    }

    void sort() {
        if(b<=a) swap(a, b);
        if(c<=a) swap(a, c);
        if(c<=b) swap(b, c);
    }

    void read() {
        scanf("%d%d%d", &a, &b, &c);
    }

};

Node getPre(Node t) {
    t.c = t.b-t.a+1;
    t.sort();
    return t;
}

//至少两个相同
bool same(Node t, Node s) {
    return (t.a==s.a&&t.b==s.b) || (t.a==s.b&&t.b==s.c) || (t.a==s.a&&t.b==s.c);
}

int main() {
    int T;
    Node s, t, pre;
    scanf("%d", &T);
    while(T--) {
        t.read();
        s.read();
        t.sort();
        s.sort();
        bool ok = false;

        if(t==s) {
            ok = true;
        } else {
            if(t.a+t.b-1!=t.c) ok = false; //!
            else {
                if(same(t, s))ok=true;
                while(t.a>=s.a) {
                    pre = getPre(t);
                    if(pre == t) break;//
                    t = pre;
                    if(same(t, s)) {
                        ok = true;
                        break;
                    }
                }
            }
        }
        printf(ok?"Yes\n":"No\n");
    };
    return 0;
}
