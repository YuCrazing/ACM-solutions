/*
* POJ 3974 Palindrome
*
* s: abaaba
* i: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
* t[i]: $ # a # b # a # a # b # a #
* p[i]: 1 1 2 1 4 1 2 7 2 1 4 1 2 1
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
char t[N<<1];
int p[N<<1];
void Manacher(char *s, int ls) {
    int lt = 0;
    t[lt++] = '$';
    t[lt++] = '#';
    for(int i = 0; i < ls; i++) {
        t[lt++] = s[i];
        t[lt++] = '#';
    }
    t[lt] = 0;

    int id = 0, mx = 0;
    for(int i = 0; i < lt; i++) {
        if(mx > i) {
            p[i] = min(mx - i, p[2 * id - i]);
        } else p[i] = 1;

        if(i) while(t[i + p[i]] == t[i - p[i]]) p[i]++;

        if(i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}

char s[N];
int main() {
    int ca = 0;
    while(scanf("%s", s) != EOF) {
        if(!strcmp(s, "END")) break;

        int ls = strlen(s); // strlen() is O(n).
        Manacher(s, ls);

        int ans = 0;
        for(int i = 0; i < 2 * ls + 2; i++) {
            ans = max(ans, p[i] - 1);
        }

        printf("Case %d: %d\n", ++ca, ans);
    }
    return 0;
}
