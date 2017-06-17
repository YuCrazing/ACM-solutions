#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;

const int N = 1005;

char t[N<<1];
int p[N<<1];
void Manacher(char *s, int n) {
    int l = 0;
    t[l++] = '$';
    t[l++] = '#';
    for(int i = 0; i < n; i++) {
        t[l++] = s[i];
        t[l++] = '#';
    }
    t[l] = 0;

    int mx = 0, id = 0;
    for(int i = 0; i < l; i++) {
        if(mx > i) {
            p[i] = min(p[2*id - i], mx - i);
        } else {
            p[i] = 1;
        }

        if(i) while(t[i + p[i]] == t[i - p[i]]) p[i]++;

        if(i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}
char s[N];
int main() {
    scanf("%s", s);

    int n = strlen(s);
    Manacher(s, n);
    int mx = 0, pos;
    for(int i = 2; i < 2*n+2; i++) {
        if(mx < p[i] - 1) {
            mx = p[i] - 1;
            pos = i;
        }
    }

    for(int i = pos - mx + 1; i < pos + mx; i++) {
        if(t[i] != '#') printf("%c", t[i]);
    }
    printf("\n");

    return 0;
}
