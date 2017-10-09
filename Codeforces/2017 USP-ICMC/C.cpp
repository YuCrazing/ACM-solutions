#include<bits/stdc++.h>
using namespace std;

struct Node {
    int cnt[20];
    bool ac[20];
    int num;
    int pen;
    int id;
    bool operator<(const Node& t)const {
        //if(num==t.num && pen==t.pen) return id>t.id;
        if(num==t.num) return pen>t.pen;
        return num<t.num;
    }
} p[202];



int n, m, k, tim, tol, ans, b, las=-1;
char name[1010], pro[1010], sta[1010];

map<string, int> mp;

void init() {
    for(int i = 0; i < n; i++) {
        memset(p[i].cnt, 0, sizeof(p[i].cnt));
        memset(p[i].ac, 0, sizeof(p[i].ac));
        p[i].pen=p[i].num=0;
        p[i].id=i;
    }
    las=0;
    b=200;
    tol=ans=0;
    mp.clear();
}

int getid(string s) {
    if(mp.find(s)!=mp.end()) return mp[s];
    else mp[s]=tol++;
    return tol-1;
}


void proc(int id, int pid, int t, int ch) {
    if(ch==0) {
        if(p[id].ac[pid]==false) p[id].cnt[pid]++;
    } else {
        if(p[id].ac[pid]) return;
        p[id].ac[pid]=true;
        p[id].num++;
        p[id].pen+=p[id].cnt[pid]*20+t;
        if(!(p[id]<p[b])) {
            p[b]=p[id];
        }
        if(las==-1) {
            if(p[b].num==p[0].num&&p[b].pen==p[0].pen) {
                las=t;
            }
        } else {
            ans+=t-las;
            if(p[b].num==p[0].num&&p[b].pen==p[0].pen)las=t;
            else las=-1;

        }
    }
}

string s;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    init();
    for(int i = 0; i < n; i++) {
        scanf("%s", &name);
        s.clear();
        for(int j = 0; name[j]; j++) s+=name[j];
        getid(s);
    }
    for(int i = 0; i < m; i++) {
        scanf("%s%s%d%s", name, pro, &tim, sta);
        s.clear();
        for(int j = 0; name[j]; j++) s+=name[j];
        int id=getid(s);
        proc(id, pro[0]-'A', tim, sta[0]=='O'?1:0);
    }
    //rintf("las = %d, ans=%d\n", las, ans);
    if(las!=-1) ans+=300-las;
    printf("%d\n", ans);
    return 0;
}
