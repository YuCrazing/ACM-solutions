#include<bits/stdc++.h>
using namespace std;

pair<int, int> pos[26];
void init(){
    int x,y;
    x=0;
    y=0;
    for(int i = 0; i < 26; ++i){
        if(i%3==0)y++;
        if(y>=3){
            y%=3;
            x++;
        }
        pos[i]={x, y};
    }
    pos[18]={2, 1-1};
    pos[19]={2, 2-1};
    pos[20]={2, 2-1};
    pos[21]={2, 2-1};
    pos[22]={2, 3-1};
    pos[23]={2, 3-1};
    pos[24]={2, 3-1};
    pos[25]={2, 3-1};
//      for(int i = 0; i < 26; ++i){
//        printf("%d %d\n", pos[i].first, pos[i].second);
//    }
}

char s[100005];
int main(){
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        pair<int, int> pre={0, 0};
        int sum=0;
        for(int i = 0; s[i]; ++i){
            pair<int, int> cur=pos[s[i]-'A'];
            sum+=abs(pre.first-cur.first)+abs(pre.second-cur.second);
            pre=cur;
        }
        printf("%d\n", sum);
    }
    return 0;
}
