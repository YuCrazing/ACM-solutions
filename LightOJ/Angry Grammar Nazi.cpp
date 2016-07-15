#include<cstring>
#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s, word[111];

int main() {
    int sk;
    stringstream ss;

    scanf("%d",&sk);
    getline(cin,s);
    while(sk--) {
        ss.clear();
        getline(cin,s);
        ss.str(s);
        int ans=0;
        int n = 0;
        while(ss >> word[n]) n ++;

        for(int i = 0; i < n; i ++) {
            if(word[i] == "u" ||word[i] == "ur") ans ++;
            else if(i < n - 1 && (word[i] == "should" ||word[i] == "would") && word[i + 1] == "of") ans ++;
            int sz = word[i].size();
            int pos = word[i].find("lol", 0);
            if(pos >=0 && pos < sz) ans ++;
        }
        printf("%d\n",ans * 10);
    }
}
