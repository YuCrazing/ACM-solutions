#include<bits/stdc++.h>
using namespace std;

int c[7];
char s[100];
int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < 7; ++i) c[i]=1e6;
    for(int i = 0; i < n; ++i) {
        scanf("%d%s", &x, s);
        if(strcmp(s, "A") == 0) c[0]=min(c[0], x);
        else if(strcmp(s, "B") == 0) c[1]=min(c[1], x);
        else if(strcmp(s, "C") == 0) c[2]=min(c[2], x);
        else if(strcmp(s, "AB") == 0 || strcmp(s, "BA") == 0) {
            c[3]=min(c[3], x);
            c[0]=min(c[0], x);
            c[1]=min(c[1], x);
        } else if(strcmp(s, "AC") == 0 || strcmp(s, "CA") == 0) {
            c[4]=min(c[4], x);
            c[0]=min(c[0], x);
            c[2]=min(c[2], x);
        } else if(strcmp(s, "BC") == 0 || strcmp(s, "CB") == 0) {
            c[5]=min(c[5], x);
            c[1]=min(c[1], x);
            c[2]=min(c[2], x);
        } else {
            for(int j = 0; j < 7; ++j) c[j]=min(c[j], x);
        }
    }
    int ans = 1e6;
    ans = min(ans, c[0]+c[1]+c[2]);
    ans = min(ans, c[0]+c[5]);
    ans = min(ans, c[1]+c[4]);
    ans = min(ans, c[2]+c[3]);
    ans = min(ans, c[6]);
    if(ans==1e6) ans = -1;
    printf("%d\n", ans);
    return 0;
}

