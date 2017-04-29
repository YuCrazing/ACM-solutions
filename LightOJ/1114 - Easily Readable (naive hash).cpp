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
    ���Ա�hack��hash��.
    ������е��ʶ���һ�����ʵĲ�ͬ���С�
    hash�󶼻�ŵ�ͬһ��vector�У���ʱ���롢���ҵĸ��Ӷ�ΪO(N^2)��
    -------
    ��һ��˼����һ�£���������˵��Ӧ���Ǵ���ġ�
    ����һ�����ʵĲ�ͬ���У���β��ĸ�Ĳ�ͬ���һ����52*52�֣�
    ���Լ�ʹ��һ�����ʵ�ȫ���У��ŵ�ͬһ��vector�еĲ�ͬ��Ҳ���ֻ��52*52����
    ��������ʵ�����˵���Ѿ���һ���ܴ�������ˡ�
    ��������£��뽵�Ͳ��ҵĸ��Ӷȣ�ֻ��ѡ������mod�ˡ�
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
