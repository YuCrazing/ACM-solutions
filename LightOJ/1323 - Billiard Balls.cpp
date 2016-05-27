#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Ball {
    int x, y;
    string dir;
    Ball() {}
    Ball(int _x, int _y, string _dir):x(_x),y(_y),dir(_dir) {}
    void update(int L, int W, int K) {
        int res;
        if(dir[0] == 'N') {
            res = (y + K)%(2*W);
            if(res <= W) y = res;
            else y = 2*W - res;
        } else {
            res = ((y - K)%(2*W) + 2*W)%(2*W);
            if(res <= W) y = res;
            else y = 2*W - res;
        }
        if(dir[1] == 'E') {
            res = (x + K)%(2*L);
            if(res <= L) x = res;
            else x = 2*L - res;
        } else {
            res = ((x - K)%(2*L) + 2*L)%(2*L);
            if(res <= L) x = res;
            else x = 2*L - res;
        }
    }
    bool operator<(const Ball b)const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
};

Ball ball[1111];
int main() {
    ios_base::sync_with_stdio(0);
    int T, L, W, K, n, _x, _y;
    string _dir;

    cin >> T;
    for(int cas = 1; cas <= T; cas ++) {
        cin >> L >> W >> n >> K;
        for(int i = 0; i < n; i ++) {
            cin >> _x >> _y >> _dir;
            ball[i] = Ball(_x, _y, _dir);
            ball[i].update(L, W, K);
        }
        sort(ball, ball + n);
        cout << "Case " << cas << ":" <<endl;
        for(int i = 0; i < n; i ++) cout << ball[i].x << " " << ball[i].y << endl;
    }
    return 0;
}
