#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+10;

struct Node {
    int son[10];
    bool end;
};

struct Trie {
    Node node[N];
    int cnt;

    void init() {
        cnt = 0;
        for(int i = 0; i < N; i++) {
            node[i].end = false;
            memset(node[i].son, 0, sizeof(node[i].son));
        }
    }

    bool insert(char* s) {
        int ls = strlen(s), cur = 0;
        bool res[2] = {true, false};
        for(int i = 0; i < ls; i++) {
            int &pos = node[cur].son[s[i] - '0'];
            if(!pos) {
                res[0] = false;
                pos = ++cnt;
            }
            cur = pos;
            if(node[pos].end) res[1] = true;
            if(i == ls - 1) node[pos].end = true;
        }
        //res[0] == true: other string is a prefix of s.
        //res[1] == true: s is a prefix of other string.
        return res[0] | res[1];
    }
} tree;

char s[20];

int main() {
    int n, T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        tree.init();
        bool ok = true;
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            if(tree.insert(s)) ok = false;

        }
        printf("Case %d: ", ca);
        printf(ok ? "YES\n" : "NO\n");
    }
    return 0;
}
