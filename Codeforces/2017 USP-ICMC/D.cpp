/*
    每一次拿出(ai+aj)%B最大的一对即可。

    O(nlogn)的做法：
    考虑每个数字最终和谁分为一组。
    按从大到小的顺序处理，对于当前的数字ai，对于满足条件ai+aj<B的aj，选取一个最大的aj，记为ak，则ai+ak<B。
    说明(ai, ak)最终会在一组，删除掉ai和ak。若不存在满足条件ai+aj<B的aj，则将ai删除并放到集合left中。

    最终，left集合中剩下一些数ai，将这些数配对。注意到对于任意ai，left数组中不存在aj，使得ai+aj<B。
    则每次从left集合删除一对最大的数即可。
*/

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
struct Node {
    int x;
    Node(int _x=0):x(_x){}
    bool operator<(const Node& t)const {
        return x>t.x;
    }
};
multiset<Node> st, lft;
int n, B, ans[N], tol;
Node t, a, b;
int main() {
    scanf("%d%d", &n, &B);
    for(int i = 0;  i < 2*n; i++) {
        scanf("%d", &t.x);
        st.insert(t);
    }
    tol=0;
    while(!st.empty()) {
        a=*st.begin();
        st.erase(st.begin());
        int mx=B-a.x-1;
        auto it=st.lower_bound(Node(mx));
        if(it==st.end()) lft.insert(a);
        else {
            b=*it;
            //printf("(%d %d)\n", a.x, b.x);
            st.erase(it);
            ans[tol++]=a.x+b.x;
        }
    }
    while(!lft.empty()) {
        a=*lft.begin();
        lft.erase(lft.begin());
        b=*lft.begin();
        lft.erase(lft.begin());
        ans[tol++]=(a.x+b.x)%B;
    }
    sort(ans, ans+tol);
    for(int i = tol-1; i >= 0; i--) printf(!i?"%d\n":"%d ", ans[i]);

    return 0;
}
/*

2 10
1 2 8 9
3 1000000000
99999999
99999999
99999999
99999999
99999999
99999999
*/
