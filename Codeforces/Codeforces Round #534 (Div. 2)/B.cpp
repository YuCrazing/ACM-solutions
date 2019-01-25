/*
    一维 消消乐，使用链表或者栈，链表太麻烦，栈更方便
*/

//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define fi first
//#define se second
//
//char s[111111];
//int nxt[111111], last[111111];
//int main() {
//    scanf("%s", s);
//    for(int i = 0; s[i]; ++i) {
//        nxt[i] = i+1;
//        last[i] = i-1;
//    }
//    int n = strlen(s);
//    int cur = 0, k = 0;
//    while(cur != n) {
//        if(nxt[cur] == n) break;
//        if(s[cur] == s[nxt[cur]]) {
//            int right = nxt[nxt[cur]];
//            int left = last[cur];
//            if(right != n) last[right] = left;
//            if(left != -1) nxt[left] = right;
//
//            if(left != -1) cur = left;
//            else cur = right;
//            ++k;
//        } else {
//            cur = nxt[cur];
//        }
//    }
//    if(k&1) printf("Yes\n");
//    else printf("No\n");
//
//    return 0;
//}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

stack<char> st;
char s[111111];
int main() {
    scanf("%s", s);
    int ct = 0;
    for(int i = 0; s[i]; ++i) {
        if(st.size() && st.top() == s[i]) {
            st.pop();
            ++ct;
        } else st.push(s[i]);
    }
    puts(ct%2?"Yes":"No");
}
