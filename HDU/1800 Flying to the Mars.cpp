#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

unordered_map<string, int> mp;

int n;
string s;
int main() {
    while(cin >> n) {
        mp.clear();
        for(int i = 0; i < n; i++) {
            cin >> s;
            int j = 0;
            while(s[j] == '0') j++; // Remove leading zeros.
            if(j == s.size()) s = "0";
            else s = s.substr(j);
            if(mp.find(s) == mp.end()) mp[s] = 1;
            else mp[s]++;
        }
        int ans = 1;
        for(unordered_map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            ans = max(ans, it->second);
        }
        cout << (n ? ans : 0) << endl;
    }
    return 0;
}
