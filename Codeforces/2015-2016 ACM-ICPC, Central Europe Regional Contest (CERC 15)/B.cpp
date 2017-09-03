#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N], b[N], n, l, r, len;
char s[N];

int main(){

    gets(s);
    scanf("%d%d", &l, &r);

    memset(b, -1, sizeof(b)); //b[i]: i位置的单词起点, i位置若为空格则为下一个单词的起点
    memset(a, -1, sizeof(a)); //a[i]: i位置的单词长度, i位置若为空格则为下一个单词的长度

    len = 0;
    n = strlen(s);
    for(int i = 0; s[i]; i++){
        if(s[i]==' '){
            b[i-1] = i-len;
            a[i-1] = len;
            len = 0;
        }else len++;
    }

    if(len) {
        b[n-1] = n-len;
        a[n-1] = len;
    }

    for(int i = n-1; i>=0; i--) if(b[i]==-1) b[i] = b[i+1];
    for(int i = n-1; i>=0; i--) if(a[i]==-1) a[i] = a[i+1];

    int ans, cur, nex;
    for(int i = l; i <= r; i++){
        ans = 0;
        cur = b[0];
        while(cur<n){
            ans += a[cur]+1;
            if(cur+i>=n) break;
            cur = b[cur+i];
        }
        printf("%d\n", ans-1);
    }
    return 0;
}
