#include<bits/stdc++.h>
using namespace std;

const int N = 100;

struct Box {

    int x, y, z;

    Box(int x=0, int y=0, int z=0):x(x),y(y),z(z){};

    void read() {
        scanf("%d%d%d", &x, &y, &z);
    }

    void sort() {
        if(y < x) swap(x, y);
        if(z < x) swap(x, z);
        if(z < y) swap(y, z);
    }

    bool operator<(const Box& t)const {
        if(x == t.x) return y > t.x;
        return x > t.x;
    }

} box[N], tbox;

int n, m, ca = 0, ans, dp[N];
int main() {
    while(scanf("%d", &n) != EOF && n) {
        m = 0;
        for(int i = 0; i < n; i++) {
            tbox.read();
            tbox.sort();
            box[m++] = tbox;
            box[m++] = Box(tbox.y, tbox.z, tbox.x);
            box[m++] = Box(tbox.x, tbox.z, tbox.y);
        }

        sort(box, box + m);

        ans = dp[0] = box[0].z;
        for(int i = 0; i < m; i++){
            int maxx = 0;
            for(int j = 0; j < i; j++){
                if(box[j].x > box[i].x && box[j].y > box[i].y) maxx = max(maxx, dp[j]);
            }
            dp[i] = maxx + box[i].z;
            ans = max(ans, dp[i]);
        }

        printf("Case %d: maximum height = %d\n", ++ca, ans);
    }
    return 0;
}
