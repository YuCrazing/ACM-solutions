#include<bits/stdc++.h>
using namespace std;

/*
    ��ѧ���⣺�ҹ��� or ĸ���� ?
*/

int main() {
    int n[3];
    while(scanf("%d%d%d", &n[0], &n[1], &n[2])) {
        if(!(n[0] || n[1] || n[2])) break;
        int ans = n[0] * 1 + n[1] * 2 + n[2] * 5 + 1;
        if(n[0] >= 4) ;
        else {
            if(n[0] == 3) {
                if(n[1]) ;
                else ans = 4;
            } else if(n[0] == 2) {
                if(n[1]) ;
                else ans = 3;
            } else if(n[0] == 1) {
                if(n[1] >= 2) ;
                else if(n[1] == 1) ans = 4;
                else ans = 2;
            } else ans = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
