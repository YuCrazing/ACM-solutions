#include<iostream>
#include<sstream>
#include<string>
#include<cassert>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
    Node* son[52];
    int num;
//    ~Node(){
//        cout << "over" << endl;
//        for(int i = 0; i < 52; i++){
//            if(son[i] != NULL){
//                delete son[i];
//                son[i] = NULL;
//            }
//        }
//    }
};

int id(char x){
    if(islower(x)) return x - 'a' + 26;
    else return x - 'A';
}

struct Trie{
    Node* root;

    void init(){
        this->root = new Node();
    }

    void check(Node* node){
        cout << node << endl;
        for(int i = 0; i < 52; i++){
            if(node->son[i] != NULL){
                check(node->son[i]);
            }
        }
    }

    void destroy(Node* cur){
        for(int i = 0; i < 52; i++){
            if(cur->son[i]){
                destroy(cur->son[i]);
                delete cur->son[i];
                cur->son[i] = NULL;
            }
        }
    }

    void insert(string& s, int ls){
        Node* cur = root;

//        ----
//        if(cur->son[index] == NULL) cur->son[index] = new Node();
//        cur = cur->son[index];
//        ----
//        cur = cur->son[index];
//        if(cur == NULL) cur = new Node();

        for(int i = 0; i < ls; i++){
            int index = id(s[i]);
            if(cur->son[index] == NULL) cur->son[index] = new Node();
            cur = cur->son[index];
            if(i == ls -1) {
                cur->num++;
                //cout <<"num: "<< cur->num << endl;
            }
        }
    }

    int search(string& s, int ls){
        Node* cur = root;
        for(int i = 0; i < ls; i ++){
            int index = id(s[i]);
            if(cur->son[index] == NULL) return 0;
            cur = cur->son[index];
            if(i == ls - 1) return cur->num;
        }
    }
}trie;
int main() {
    //freopen("1114.in", "r", stdin);
    //freopen("1114.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T, n, m;
    string word, sentence;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        trie.init();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> word;
            int lw = word.size();
            if(lw > 2) sort(word.begin() + 1, word.end() - 1);
            trie.insert(word, lw);
        }

        printf("Case %d:\n", ca);
        cin >> m;
        cin.ignore(); //important
        for(int i = 0; i < m; i++) {
            getline(cin, sentence);
            stringstream ss(sentence);
            int res = 1;
            while(ss >> word) {
                int lw = word.size();
                if(lw > 2) sort(word.begin() + 1, word.end() - 1);
                int cnt = trie.search(word, lw);
                res *= cnt;
                if(cnt == 0) break;
            }
            printf("%d\n", res);
        }
        trie.destroy(trie.root);
        //trie.check(trie.root);
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
