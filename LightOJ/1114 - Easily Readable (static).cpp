#include<iostream>
#include<sstream>
#include<cstdio>
#include<cassert>
#include<string>
#include<algorithm>

using namespace std;

/*
    assert(sizeof(int*) == 2 * sizeof(int));
    assert(sizeof(int*) == 8);
    assert(sizeof(int) == 4);
*/

const int N = 1e5 + 1;

struct Node {
    int son[52];
    int num;
};

int id(char x) {
    if(islower(x)) return x - 'a' + 26;
    else return x - 'A';
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

    void check(int pos, string s) {
        cout << s << pos << endl;
        s += "  ";
        for(int i = 0; i < 52; i++) {
            if(node[pos].son[i]) check(node[pos].son[i], s);
        }
    }

    void insert(string& s, int ls) {
        int pos = 0;
        for(int i = 0; i < ls; i++) {
            int index = id(s[i]);
            if(!node[pos].son[index]) node[pos].son[index] = tol++;
            pos = node[pos].son[index];
            if(i == ls - 1) node[pos].num++;
        }
    }

    int search(string& s, int ls) {
        int pos = 0;
        for(int i = 0; i < ls; i++) {
            int index = id(s[i]);
            if(!node[pos].son[index]) return 0;
            pos = node[pos].son[index];
            if(i == ls - 1) return node[pos].num;
        }
    }
} trie;
int main() {

    //freopen("1114.in", "r", stdin);
    //freopen("1114.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, m;
    string word, sentence;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        trie.init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> word;
            int ls = word.size();
            if(ls > 3) sort(word.begin() + 1, word.end() - 1);
            trie.insert(word, ls);
        }

        printf("Case %d:\n", ca);
        //cout << "Case " << ca << ":" << endl;
        cin >> m;
        cin.ignore(); //important
        for(int i = 0; i < m; i++) {
            getline(cin, sentence);
            stringstream ss(sentence);
            int res = 1;
            while(ss >> word) {
                int ls = word.size();
                if(ls > 3) sort(word.begin() + 1, word.end() - 1); //sort(first, last), first must <= last.
                int cnt = trie.search(word, ls);
                res *= cnt;
                if(cnt == 0) break;
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
