#include <bits/stdc++.h>
#define N 3001
#define LOG 13
#define INF 100000

using namespace std;

vector <int> graph[N];
int ans[400005];
int goup[N][LOG];
int dist[N];
bool cycle;
int n;
int atual;
bool visited[N];
bool visited2[N];
void visiteall (int v){
    if (visited[v]) return;
    visited[v] = true;
    for (auto u: graph[v]) visiteall(u);
}

void dfs (int v){
    //printf("v=%d\n", v);
    visited2[v] = true;
    for (auto u: graph[v]){
        if (!visited[u] && !visited2[u]){
            dist[u] = dist[v] + 1;
            goup[u][0] = v;
            dfs(u);
        }
        if (visited2[u])
            visiteall(u);
    }
}

int build (int v){
    for (int i = 0; i < N; i++){
        dist[i] = INF;
        visited2[i] = 0;
        visited[i] = 0;

    }
    dist[v] = 0;
    cycle = false;
    dfs (v);
    for (int i = 1; i < LOG; i++)
        for (int j = 1; j <= n; j++)
            goup[j][i] = goup[goup[j][i-1]][i-1];

}

int query (int b, int k){
    /*
    printf ("\nv = %d\n", atual);
    printf ("u = %d\n", b);
    printf ("k = %d\n", k);
    printf ("dist[b] = %d\n", dist[b]);
    */
    if (dist[b] + 1 < k) return -1;
    if (dist[b] > n) return -1;
    int subida = dist[b] + 1 - k;
    for (int i = 12; i >= 0; i--){
        if ((1<<i) <= subida){
            b = goup[b][i];
            subida -= (1<<i);
        }
    }
    // printf ("kth = %d\n", b);
    return b;
}

int main(){

    int m, q;
    scanf ("%d %d %d", &n, &m, &q);
    while (m--){
        int a, b;
        scanf ("%d %d", &a, &b);
        graph[a].push_back (b);
    }
    for (int i = 1; i <= n; i++) sort (graph[i].begin(), graph[i].end());
    vector <tuple<int, int, int, int>> queries;

    for (int i = 0; i < q; i++){
        int a, b, k;
        scanf ("%d %d %d", &a, &b, &k);
        queries.emplace_back (a, b, k, i);


    }

    sort (queries.begin(), queries.end());

    for (auto q: queries){
        int a, b, k, ith;
        tie (a, b, k, ith) = q;
        if (a != atual){
            build(a);
            atual = a;
        }
        ans[ith] = query(b, k);
    }
    for (int i = 0; i < q; i++)
        printf ("%d\n", ans[i]);
    return 0;
}
/*

5 5 1
1 2
2 3
3 4
4 2
3 5
1 5 3

*/
