#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/*
    hash的关键在于只对中间的字符进行排序，首尾字母不参与排序。
    cout换成printf之后效率提高了20倍。
*/

const long long mod = 23333333333333333;
vector<long long> a;

long long gethash(string& s){
    int l = s.size();
    long long sum = 0;
    for(int i = 0; i < l; i++){
        sum *= 2333;
        sum += s[i];
        sum %= mod;
    }
    return sum;
}

void insert(string& s){
    a.push_back(gethash(s));
}

int search(string& s){

    long long hashvalue = gethash(s);

    int last = upper_bound(a.begin(), a.end(), hashvalue) - a.begin();
    int first = lower_bound(a.begin(), a.end(), hashvalue) - a.begin();
    if(a[first] != hashvalue) return 0;
    return last - first;
}

int main() {
    //freopen("1114.in", "r", stdin);
    //freopen("1114.out", "w", stdout);
    ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T, n, m;
    string word, sentence;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {

        a.clear();

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> word;
            if(word.size() > 2) sort(word.begin() + 1, word.end() - 1); //important
            insert(word);
        }

        sort(a.begin(), a.end());

        printf("Case %d:\n", ca);
        //cout << "Case " << ca << ":" << endl;
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
            //cout << res << endl;
        }
    }
    return 0;
}
