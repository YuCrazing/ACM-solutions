#include<bits/stdc++.h>
#define mk make_pair
using namespace std;

const int N = 3;
const int S = 100;

struct Box {
    int x, y, z;

    void read() {
        scanf("%d%d%d", &x, &y, &z);
    }

    void sort() {
        if(y < x) swap(x, y);
        if(z < x) swap(x, z);
        if(z < y) swap(y, z);
    }

} box[33];

int n, ca = 0, dp[S], in[S], g[S][S];
vector<int> fa[S], son[S];

void add(int u, int v, int w) {
    fa[v].push_back(u);
    son[u].push_back(v);
    g[u][v] = w;
    in[v]++;
}

void init() {

    for(int i = 0; i < S; i++) {
        in[i] = 0;
        for(int j = 0; j < S; j++)
            g[i][j] = -1;
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            son[i*N+j].clear();
            fa[i*N+j].clear();
        }
    }

    int sti;
    for(int i = 0; i < n; i++) {
        sti = i * N;
        for(int j = 0; j < n; j++) {
            if(box[j].x < box[i].x && box[j].y < box[i].y) add(sti, j*N, box[j].z);
            if(box[j].y < box[i].x && box[j].z < box[i].y) add(sti, j*N+1, box[j].x);
            if(box[j].x < box[i].x && box[j].z < box[i].y) add(sti, j*N+2, box[j].y);
        }

        sti = i * N + 1;
        for(int j = 0; j < n; j++) {
            if(box[j].x < box[i].y && box[j].y < box[i].z) add(sti, j*N, box[j].z);
            if(box[j].y < box[i].y && box[j].z < box[i].z) add(sti, j*N+1, box[j].x);
            if(box[j].x < box[i].y && box[j].z < box[i].z) add(sti, j*N+2, box[j].y);
        }

        sti = i * N + 2;
        for(int j = 0; j < n; j++) {
            if(box[j].x < box[i].x && box[j].y < box[i].z) add(sti, j*N, box[j].z);
            if(box[j].y < box[i].x && box[j].z < box[i].z) add(sti, j*N+1, box[j].x);
            if(box[j].x < box[i].x && box[j].z < box[i].z) add(sti, j*N+2, box[j].y);
        }
    }
}

int topo() {
    queue<int> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            if(!in[i*N+j]) q.push(i*N+j);
        }
    }

    int ans = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int id = u / N;
        int s = u % N;
        if(!fa[u].size()) {
            if(s==0) dp[u] = box[id].z;
            else if(s==1) dp[u] = box[id].x;
            else dp[u] = box[id].y;
        } else {
            int maxx = 0;
            for(int i = 0; i < fa[u].size(); i++) {
                maxx = max(maxx, dp[fa[u][i]] + g[fa[u][i]][u]);
            }
            dp[u] = maxx;
        }
        ans = max(ans, dp[u]);

        for(int i = 0; i < son[u].size(); i++) {
            int v = son[u][i];
            in[v]--;
            if(!in[v])q.push(v);
        }
    }
    return ans;
}


int main() {
    while(scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < n; i++) {
            box[i].read();
            box[i].sort();
        }

        init();

        printf("Case %d: maximum height = %d\n", ++ca, topo());
    }
    return 0;
}
