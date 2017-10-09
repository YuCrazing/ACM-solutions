#include<bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    Node(int _x=0, int _y=0):x(_x),y(_y) {}
};

vector<Node> v[26];
bool check(Node t, int ch) {
    int k=0;
    for(int i = 0; i < v[ch].size(); i++) {
        if(v[ch][i].x==t.x)k++;
        else if(v[ch][i].y==t.y)k++;
    }
    if(k<3) return true;
    return false;
}

void init() {
    for(int i = 0; i < 26; i++) v[i].clear();
}

char s[30];
int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        init();
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            for(int j = 0; j < n; j++) {
                v[s[j]-'A'].push_back(Node(i, j));
            }
        }
        int ans;
        Node t;
        for(int i = 0; i < 26; i++) if(v[i].size()==n-1) {
                ans=i;
                break;
            }

        bool ok=false;
        for(int i = 0; i < 26; i++) if(v[i].size()==1) {
                t=v[i][0];
                ok=true;
                break;
            }

        if(!ok) {
            for(int i=0; i<26; i++) {
                if(v[i].size()==n+1) {
                    for(int j = 0; j < v[i].size(); j++) {
                        if(check(v[i][j], i)==false) {
                            t=v[i][j];
                        }
                    }
                    break;
                }
            }
        }
        printf("%d %d %c\n", t.x+1, t.y+1, ans+'A');
    }
    return 0;
}
