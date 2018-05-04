#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 5;
const ull P = 1e9 + 7;

ll A, B, C, D, L;
int ans, n, T;
ull p[26];

unordered_set<ull> st[26][26];
vector<string> v[100005];
string s, ss;

ll getNext(ll x, ll y) {
    return (A * x + B * y + C) % D;
}

void init() {
    for(int i = 0; i < 100005; ++i) v[i].clear();
    for(int i = 0; i < 26; ++i) p[i] = (i ? p[i-1]*P : 1);
    ans = 0;
}

ull has(string &str) {
    ull r = 0;
    for(int i = 0; i < str.size(); ++i) r += p[str[i]-'a'];
    return r;
}


int main() {
    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < 26; ++j) {
            st[i][j].max_load_factor(0.25);
            st[i][j].reserve(500);
        }

//    st.max_load_factor(0.25);
//    st.reserve(500);

    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large-practice.out", "w", stdout);
//    freopen("C-small-practice.in", "r", stdin);
//    freopen("C-small-practice.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        init();
        cin >> L;
        for(int i = 0; i < L; ++i) {
            cin >> s;
            v[s.size()].push_back(s);
//            cout<<"   "<< s.size() <<endl;
//            cerr<<"   "<<s.size() << " " << s <<endl;
        }

        cin >> s >> ss >> n >> A >> B >> C >> D;

        int ind = 2, asi, nex = ss[0], pre = s[0];
        s += ss[0];
        while(ind < n) {
            ll neww = getNext(nex, pre);
            int asi = neww%26+97;
            s += (char)asi;
            pre = nex;
            nex = neww;
            ++ind;
        }
//        cerr << s << endl;
        int ct=0;
        for(int len = 1; len < 100005; ++len) {
            if(v[len].size()==0) continue;
            if(len > s.size()) break;

            ull r=0;
            for(int i = 0; i < len; ++i) r += p[s[i]-'a'];

            for(int i = 0; i < 26; ++i)
                for(int j = 0; j < 26; ++j)
                    st[i][j].clear();
            st[s[0]-'a'][s[len-1]-'a'].insert(r);

            for(int i = 1; i+len-1 < s.size(); ++i) {
                r -= p[s[i-1]-'a'];
                r += p[s[len+i-1]-'a'];
                st[s[i]-'a'][s[i+len-1]-'a'].insert(r);
            }

            for(int i = 0; i < v[len].size(); ++i){
                string& str = v[len][i];
                int a=str[0]-'a';
                int b=str[str.size()-1]-'a';
                ull c=has(str);
                if(st[a][b].find(c)!=st[a][b].end()) ++ans;
            }

            ct++;
            cerr << "len = " << len << " ct = " << ct << " num = " << v[len].size() << " s.size() = " << s.size() << endl;
        }
        cerr << ca << endl;
        cout << "Case #" << ca << ": " << ans << endl;
    }

    return 0;
}

