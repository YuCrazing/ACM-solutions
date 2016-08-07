#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
int vis[10][10][10][10][10][10], n;

struct Node {
    int x[3], y[3];

//    void sort() {
//        if(x[1] > x[2] || (x[1] == x[2] && y[1] > y[2])) {
//            swap(x[1], x[2]);
//            swap(y[1], y[2]);
//        }
//        if(x[0] > x[1] || (x[0] == x[1] && y[0] > y[1])) {
//            swap(x[0], x[1]);
//            swap(y[0], y[1]);
//        }
//        if(x[1] > x[2] || (x[1] == x[2] && y[1] > y[2])) {
//            swap(x[1], x[2]);
//            swap(y[1], y[2]);
//        }
//    }

    void show() {
        for(int i = 0; i < 3; i ++) printf("(%d %d) ", x[i], y[i]);
        printf("%d\n", vis[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]] - 1);
    }
};

char mp[10][20];
Node src, dst;

int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool ok(int x, int y) {
    return mp[x][y] != '#' && x < n && x >= 0 && y < n && y >= 0;
}

Node move(Node s, int d) {

    Node t = s;
    for(int i = 0; i < 3; i ++) if(ok(t.x[i] + dir[d][0], t.y[i] + dir[d][1])) {
            t.x[i] += dir[d][0];
            t.y[i] += dir[d][1];
        }

    if(s.x[0] + dir[d][0] == s.x[1] && s.y[0] + dir[d][1] == s.y[1]
            && s.x[1] + dir[d][0] == s.x[2] && s.y[1] + dir[d][1] == s.y[2]) {
        if(ok(s.x[2] + dir[d][0], s.y[2] + dir[d][1])) return t;
        return s;
    } else if(s.x[0] + dir[d][0] == s.x[2] && s.y[0] + dir[d][1] == s.y[2]
              && s.x[2] + dir[d][0] == s.x[1] && s.y[2] + dir[d][1] == s.y[1]) {
        if(ok(s.x[1] + dir[d][0], s.y[1] + dir[d][1])) return t;
        return s;
    } else if(s.x[1] + dir[d][0] == s.x[0] && s.y[1] + dir[d][1] == s.y[0]
              && s.x[0] + dir[d][0] == s.x[2] && s.y[0] + dir[d][1] == s.y[2]) {
        if(ok(s.x[2] + dir[d][0], s.y[2] + dir[d][1])) return t;
        return s;
    } else if(s.x[1] + dir[d][0] == s.x[2] && s.y[1] + dir[d][1] == s.y[2]
              && s.x[2] + dir[d][0] == s.x[0] && s.y[2] + dir[d][1] == s.y[0]) {
        if(ok(s.x[0] + dir[d][0], s.y[0] + dir[d][1])) return t;
        return s;
    } else if(s.x[2] + dir[d][0] == s.x[0] && s.y[2] + dir[d][1] == s.y[0]
              && s.x[0] + dir[d][0] == s.x[1] && s.y[0] + dir[d][1] == s.y[1]) {
        if(ok(s.x[1] + dir[d][0], s.y[1] + dir[d][1])) return t;
        return s;
    } else if(s.x[2] + dir[d][0] == s.x[1] && s.y[2] + dir[d][1] == s.y[1]
              && s.x[1] + dir[d][0] == s.x[0] && s.y[1] + dir[d][1] == s.y[0]) {
        if(ok(s.x[0] + dir[d][0], s.y[0] + dir[d][1])) return t;
        return s;
    }

    else if(s.x[0] + dir[d][0] == s.x[1] && s.y[0] + dir[d][1] == s.y[1]) {
        if(ok(s.x[1] + dir[d][0], s.y[1] + dir[d][1])) return t;
        else {
            t.x[0] = s.x[0];
            t.y[0] = s.y[0];
            return t;
        }
    } else if(s.x[1] + dir[d][0] == s.x[0] && s.y[1] + dir[d][1] == s.y[0]) {
        if(ok(s.x[0] + dir[d][0], s.y[0] + dir[d][1])) return t;
        else {
            t.x[1] = s.x[1];
            t.y[1] = s.y[1];
            return t;
        }
    } else if(s.x[0] + dir[d][0] == s.x[2] && s.y[0] + dir[d][1] == s.y[2]) {
        if(ok(s.x[2] + dir[d][0], s.y[2] + dir[d][1])) return t;
        else {
            t.x[0] = s.x[0];
            t.y[0] = s.y[0];
            return t;
        }
    } else if(s.x[2] + dir[d][0] == s.x[0] && s.y[2] + dir[d][1] == s.y[0]) {
        if(ok(s.x[0] + dir[d][0], s.y[0] + dir[d][1])) return t;
        else {
            t.x[2] = s.x[2];
            t.y[2] = s.y[2];
            return t;
        }
    } else if(s.x[1] + dir[d][0] == s.x[2] && s.y[1] + dir[d][1] == s.y[2]) {
        if(ok(s.x[2] + dir[d][0], s.y[2] + dir[d][1])) return t;
        else {
            t.x[1] = s.x[1];
            t.y[1] = s.y[1];
            return t;
        }
    } else if(s.x[2] + dir[d][0] == s.x[1] && s.y[2] + dir[d][1] == s.y[1]) {
        if(ok(s.x[1] + dir[d][0], s.y[1] + dir[d][1])) return t;
        else {
            t.x[2] = s.x[2];
            t.y[2] = s.y[2];
            return t;
        }
    }

    return t;
}

bool valid(Node& s) {
    return !vis[s.x[0]][s.y[0]][s.x[1]][s.y[1]][s.x[2]][s.y[2]];
}

void mark(Node& s, Node &t) {
    vis[t.x[0]][t.y[0]][t.x[1]][t.y[1]][t.x[2]][t.y[2]] =
        vis[s.x[0]][s.y[0]][s.x[1]][s.y[1]][s.x[2]][s.y[2]] + 1;
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    queue<Node> Q;
    Q.push(src);
    vis[src.x[0]][src.y[0]][src.x[1]][src.y[1]][src.x[2]][src.y[2]] = 1;

    Node u, v;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i ++) {
            v = move(u, i);

            if(valid(v)) {
                mark(u, v);
                Q.push(v);
            }
        }
    }
}

int calc() {
    int res = inf;
    if(vis[dst.x[0]][dst.y[0]][dst.x[1]][dst.y[1]][dst.x[2]][dst.y[2]])
        res = min(res, vis[dst.x[0]][dst.y[0]][dst.x[1]][dst.y[1]][dst.x[2]][dst.y[2]] - 1);
    if(vis[dst.x[0]][dst.y[0]][dst.x[2]][dst.y[2]][dst.x[1]][dst.y[1]])
        res = min(res, vis[dst.x[0]][dst.y[0]][dst.x[2]][dst.y[2]][dst.x[1]][dst.y[1]] - 1);
    if(vis[dst.x[1]][dst.y[1]][dst.x[0]][dst.y[0]][dst.x[2]][dst.y[2]])
        res = min(res, vis[dst.x[1]][dst.y[1]][dst.x[0]][dst.y[0]][dst.x[2]][dst.y[2]] - 1);
    if(vis[dst.x[1]][dst.y[1]][dst.x[2]][dst.y[2]][dst.x[0]][dst.y[0]])
        res = min(res, vis[dst.x[1]][dst.y[1]][dst.x[2]][dst.y[2]][dst.x[0]][dst.y[0]] - 1);
    if(vis[dst.x[2]][dst.y[2]][dst.x[0]][dst.y[0]][dst.x[1]][dst.y[1]])
        res = min(res, vis[dst.x[2]][dst.y[2]][dst.x[0]][dst.y[0]][dst.x[1]][dst.y[1]] - 1);
    if(vis[dst.x[2]][dst.y[2]][dst.x[1]][dst.y[1]][dst.x[0]][dst.y[0]])
        res = min(res, vis[dst.x[2]][dst.y[2]][dst.x[1]][dst.y[1]][dst.x[0]][dst.y[0]] - 1);
    return res;
}
int main() {
//    freopen("out.txt", "w", stdout);
    int T, ct1, ct2;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);

        ct1 = ct2 = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%s", mp[i]);
            for(int j = 0; j < n; j ++) {
                if(mp[i][j] == 'A' || mp[i][j] == 'B' || mp[i][j] == 'C') {
                    src.x[ct1] = i;
                    src.y[ct1 ++] = j;
                } else if(mp[i][j] == 'X') {
                    dst.x[ct2] = i;
                    dst.y[ct2 ++] = j;
                }
            }
        }

        bfs();
        int res = calc();
        printf("Case %d: ", cas);
        if(res == inf) printf("trapped\n");
        else printf("%d\n", res);

    }
    return 0;
}
/*
10
3
.AC
#.B
XXX
5
A.#.#
XX.B.
C#..X
#.#..
#..##
*/
