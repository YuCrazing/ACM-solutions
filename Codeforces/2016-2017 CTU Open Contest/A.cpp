#include<bits/stdc++.h>
using namespace std;
map<string, char> mp;

void init() {
    mp[".-"]='A';
    mp["-..."]='B';
    mp["-.-."]='C';
    mp["-.."]='D';
    mp["."]='E';
    mp["..-."]='F';
    mp["--."]='G';
    mp["...."]='H';
    mp[".."]='I';
    mp[".---"]='J';
    mp["-.-"]='K';
    mp[".-.."]='L';
    mp["--"]='M';
    mp["-."]='N';
    mp["---"]='O';
    mp[".--."]='P';
    mp["--.-"]='Q';
    mp[".-."]='R';
    mp["..."]='S';
    mp["-"]='T';
    mp["..-"]='U';
    mp["...-"]='V';
    mp[".--"]='W';
    mp["-..-"]='X';
    mp["-.--"]='Y';
    mp["--.."]='Z';
    mp[""]=' ';
}
string s;
int main() {
    init();
    while(cin>>s) {
        for(int i = 0; i < s.size();) {
            int j;
            for(j = i; j<s.size()&&s[j]!='/'; j++) {}
            printf("%c", mp[s.substr(i, j-i)]);
            i=j+1;
        }
        puts("");
    }
    return 0;
}
