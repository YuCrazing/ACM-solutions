#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 1;


struct Node {
    int son[52];
    int num;
};

int id(char x) {
    int i = x - 'A';
    i = i > 25 ? i - ('a' - 'A') + 26 : i;
    return i;
}

struct Trie {
    Node node[N];
    int tol;

    void init() {
        for(int i = 0; i < tol; i++) {
            for(int j = 0; j < 52; j++) node[i].son[j] = 0;
            node[i].num = 0;
        }
        tol = 1;
    }

//    void check(int pos, string s) {
//        cout << s << pos << endl;
//        s += "  ";
//        for(int i = 0; i < 52; i++) {
//            if(node[pos].son[i]) check(node[pos].son[i], s);
//        }
//    }

    void insert(char* s, int ls) {
        int pos = 0;
        for(int i = 0; i < ls; i++) {
            int index = id(s[i]);
            if(!node[pos].son[index]) node[pos].son[index] = tol++;
            pos = node[pos].son[index];
            if(i == ls - 1) node[pos].num++;
        }
    }

    int search(char* s, int ls) {
        int pos = 0;
        for(int i = 0; i < ls; i++) {
            int index = id(s[i]);
            if(!node[pos].son[index]) return 0;
            pos = node[pos].son[index];
            if(i == ls - 1) return node[pos].num;
        }
    }
} trie;

char word[N], sentence[N];

int main() {

    //freopen("1114.in", "r", stdin);
    //freopen("1114.out", "w", stdout);

    int T, n, m;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        trie.init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s",word);
            int ls = strlen(word);
            if(ls > 3) sort(word + 1, word + ls - 1);
            trie.insert(word, ls);
            //trie.check(0, "");
        }

        printf("Case %d:\n", ca);
        scanf("%d", &m);
        gets(sentence);
        for(int i = 0; i < m; i++) {
            gets(sentence);
            int res = 1;
            char* tword = strtok(sentence, " ");
            while(tword != NULL) {
                int ls = strlen(tword);
                if(ls > 3) sort(tword + 1, tword + ls - 1); //sort(first, last), first <= last.
                int cnt = trie.search(tword, ls);
                res *= cnt;
                if(cnt == 0) break;
                tword = strtok(NULL, " ");
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
/*
1
9
baggers
beggars
begagrs
in
the
blowed
bowled
barn
bran
1
beggars bowled in the barn
*/
