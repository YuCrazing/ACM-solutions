#include<bits/stdc++.h>
using namespace std;

char s[300010];
char t[20] = "happiness";

bool ok(int pos) {
    for(int i = 0; i < 9; i++) {
        if(s[i+pos]!=t[i]) return false;
    }
    return true;
}

int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);
    int x, y, num;
    num = 0;
    x = y = -1;
    for(int i = 1; i+8 <= n; i++) {
        if(ok(i)) {
            num++;
            if(x==-1)x=i;
            else if(y==-1)y=i;
            i+=8;
        }
    }
    if(num>=3) {
        printf("NO\n");
    } else {
        int a, b;
        if(num==2) {
            a=x;
            b=y+1;
        } else if(num==1) {
            a=x;
            b=x+1;
        } else if (num==0) {
            swap(s[1], s[2]);
            if(n>=9&&ok(1)) {
                a=2;
                b=3;
            }
             else if(n>=10&&ok(2)){
                a=2;
                b=3;
            }
            else{
                a=1;
                b=2;
            }
            swap(s[1], s[2]);
        }
        swap(s[a], s[b]);
        for(int i = 1; i+8 <= n; i++) if(ok(i))assert(0);
        printf("YES\n");
        printf("%d %d\n", a, b);
    }
    return 0;
}
