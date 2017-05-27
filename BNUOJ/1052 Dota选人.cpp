#include<bits/stdc++.h>
using namespace std;

struct Node {
    char name[22];
    int x;

    bool operator<(const Node& t)const {
        return x < t.x;
    }

    void read() {
        scanf("%s%d", name, &x);
    }
};
Node t;
vector<Node> a[6];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        t.read();
        for(int j = 1; j <= 5; j++)
            if(t.x > j*100 && t.x < (j+1)*100) {
                a[j].push_back(t);
                break;
            }
    }
    for(int i = 1; i <= 5; i++) {
        sort(a[i].begin(), a[i].end());
        Node pre, cur;
        pre.x = cur.x = -1;
        for(int j = a[i].size() - 1; j >= 0; j--) {
            cur = a[i][j];
            if(cur.x < i * 100 + 50) break;
            pre = a[i][j];
        }
        assert(cur.x != -1);
        if(cur.x != pre.x && pre.x != -1){
            if(i*100+50 - cur.x >= pre.x - i*100-50) cur = pre;
        }
        printf("%s %d\n", cur.name, cur.x);
    }
    return 0;
}
/*

6
a 150
b 250
c 349
d 360
e 450
f 550

*/
