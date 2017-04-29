#include<iostream>
#include<sstream>
#include<string>
#include<cassert>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
    可以被hack的hash法.
    如果所有单词都是一个单词的不同排列。
    hash后都会放到同一个vector中，此时插入、查找的复杂度为O(N^2)。
    -------
    进一步思考了一下，上面这种说法应该是错误的。
    对于一个单词的不同排列，首尾字母的不同组合一共是52*52种，
    所以即使是一个单词的全排列，放到同一个vector中的不同项也最多只有52*52个。
    不过，其实相对来说这已经是一个很大的数字了。
    这种情况下，想降低查找的复杂度，只能选择更大的mod了。
*/

const int mod = 1087623;
struct node{
    string word;
    char ch[2];
    int num;
    node(){};
    node(string _word, char x, char y, int _num):
        word(_word),num(_num)
    {
        ch[0] = x;
        ch[1] = y;
    };

};
vector<node> a[mod];

int hash(string& s){
    int l = s.size();
    long long sum = 0;
    for(int i = 0; i < l; i++){
        sum *= 37;
        sum += s[i] - 'A';
        sum %= mod;
    }
    return sum;
}

void insert(char x, char y, string& s){
    int id = hash(s);
    int sz = a[id].size();
    int ls = s.size();
    bool find = false;
    for(int i = 0; i < sz; i++){
        node& word = a[id][i];
        int lw = word.word.size();
        if(word.word == s && lw == ls && word.ch[0] == x && word.ch[1] == y){
            word.num ++;
            find = true;
            break;
        }
    }

    if(!find){
        node t(s, x, y, 1);
        a[id].push_back(t);
    }

    return ;
}

int search(char x, char y, string& s){
    int id = hash(s);
    int sz = a[id].size();
    int ls = s.size();
    for(int i = 0; i < sz; i++){
        node& word = a[id][i];
        int lw = word.word.size();
        if(word.word == s && lw == ls && word.ch[0] == x && word.ch[1] == y)
            return word.num;
    }

    return 0;//important!
    //assert(false);//useful
}

int main() {
    //freopen("1114.in", "r", stdin);
    //freopen("1114.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n, m;
    string word, sentence;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        for(int k = 0; k < mod; k++){
            a[k].clear();
        }

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> word;
            char x = word[0];
            char y = word[word.size() - 1];
            sort(word.begin(), word.end());
            insert(x, y, word);
        }

        printf("Case %d:\n", ca);
        cin >> m;
        cin.ignore(); //important
        for(int i = 0; i < m; i++) {
            getline(cin, sentence);
            stringstream ss(sentence);
            int res = 1;
            while(ss >> word) {
                char x = word[0];
                char y = word[word.size() - 1];
                sort(word.begin(), word.end());
                res *= search(x, y, word);
                if(res == 0) break;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
