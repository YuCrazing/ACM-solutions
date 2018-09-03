#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

struct Time{
    int y, m, d, hh, mm, ss, sss;
    void read(){
        scanf("%d.%d.%d%2d:%2d:%2d.%3d", &y, &m, &d, &hh, &mm, &ss, &sss);
    }
};
struct Task{
    int s, t;
    Time time;
}task[20];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &task[i].s, &task[i].t);
        task[i].time.read();
    }
    return 0;
}
