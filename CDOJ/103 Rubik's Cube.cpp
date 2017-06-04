#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int L = 2003;
const int N = 55;

int p[12][5][4]= {
    {{1,3,9,7},{2,6,8,4},{15,12,21,18},{13,10,19,16},{14,11,20,17}}, // U
    {{16,18,42,40},{17,30,41,28},{15,3,43,48},{39,9,19,54},{27,6,31,51}}, // R
    {{13,15,39,37},{14,27,38,25},{12,9,40,46},{36,7,16,48},{8,28,47,24}}, // F
    {{46,48,54,52},{47,51,53,49},{37,40,43,34},{39,42,45,36},{38,41,44,35}}, // D
    {{10,12,36,34},{11,24,35,22},{7,37,52,21},{1,13,46,45},{4,25,49,33}}, // L
    {{19,21,45,43},{20,33,44,31},{1,34,54,18},{3,10,52,42},{2,22,53,30}}, // B

    {{7,9,3,1},{4,8,6,2},{18,21,12,15},{16,19,10,13},{17,20,11,14}}, // U'
    {{40,42,18,16},{28,41,30,17},{48,43,3,15},{54,19,9,39},{51,31,6,27}}, // R'
    {{37,39,15,13},{25,38,27,14},{46,40,9,12},{48,16,7,36},{24,47,28,8}}, // F'
    {{52,54,48,46},{49,53,51,47},{34,43,40,37},{36,45,42,39},{35,44,41,38}}, // D'
    {{34,36,12,10},{22,35,24,11},{21,52,37,7},{45,46,13,1},{33,49,25,4}}, // L'
    {{43,45,21,19},{31,44,33,20},{18,54,34,1},{42,52,10,3},{30,53,22,2}} // B'
};

int now[N], go[N][18], T;
bool vis[N];

void init() {
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < N; j++) go[j][i] = j;

    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 4; k++)
                go[p[i][j][k]][i] = p[i][j][(k + 1)%4];
}

void proc(int x, int cnt) {
    for(int k = 0; k < cnt; k++) {
        for(int i = 0; i < N; i++) {
            now[i] = go[now[i]][x];
        }
    }
}

ull calc() {

    memset(vis, 0, sizeof(vis));

//    for(int i = 1; i < 54; i++) printf("%d: %d\n", i, now[i]);

    ull lcm = 1;
    for(int i = 1; i <= 54; i++) {
        if(vis[i]) continue;

        ull cur = i, loop = 0;
        while(now[cur] != i) {
            vis[cur] = 1;
            cur = now[cur];
            loop++;
        }
        vis[cur] = 1;
        loop++;
        lcm = lcm / __gcd(lcm, loop) * loop;
    }
    return lcm;
}

char s[L];
int main() {

    init();

    scanf("%d", &T);
    gets(s);
    for(int ca = 1; ca <= T; ca++) {

        for(int i = 0; i < N; i++) now[i] = i;

        gets(s);
        int n = strlen(s);
        int i = 0, x, cnt;
        while(i < n) {

            char op = s[i];

            switch (op) {
            case 'U':
                x = 0;
                break;
            case 'R':
                x = 1;
                break;
            case 'F':
                x = 2;
                break;
            case 'D':
                x = 3;
                break;
            case 'L':
                x = 4;
                break;
            case 'B':
                x = 5;
                break;
            default:
                assert(0);
                break;
            }

            if(s[i+1] == '\'') {
                x += 6;
                i++;
            }

            if(s[i+1] == '2') {
                cnt = 2;
                i++;
            } else cnt = 1;

            proc(x, cnt);

            i += 2;

        }

        printf("%llu\n", calc());

    }
    return 0;
}
