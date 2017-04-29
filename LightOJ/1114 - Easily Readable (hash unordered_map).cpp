#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;

typedef long long ll;

const long long mod = 23333333333333333;
unordered_map<ll, int> mp;

ll gethash(string& s){
    int l = s.size();
    ll sum = 0;
    for(int i = 0; i < l; i++){
        sum *= 2333;
        sum += s[i];
        sum %= mod;
    }
    return sum;
}

void insert(string& s){
    ll hashvalue = gethash(s);
    if(mp.find(hashvalue) != mp.end()) mp[hashvalue]++;
    else mp[hashvalue] = 1;
}

int search(string& s){
    ll hashvalue = gethash(s);
    if(mp.find(hashvalue) != mp.end()) return mp[hashvalue];
    else return 0;
}

int main(){

    //freopen("1114.in", "r", stdin);
    //freopen("1114.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n, m;
    string word, sentence;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {

        mp.clear();

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> word;
            if(word.size() > 2) sort(word.begin() + 1, word.end() - 1);
            insert(word);
        }

        printf("Case %d:\n", ca);
        cin >> m;
        cin.ignore(); //important
        for(int i = 0; i < m; i++) {
            getline(cin, sentence);
            stringstream ss(sentence);
            int res = 1;
            while(ss >> word) {
                if(word.size() > 2) sort(word.begin() + 1, word.end() - 1);
                res *= search(word);
                if(res == 0) break;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
