<<<<<<< HEAD
=======
/*
    unordered_set: 274s
    unordered_map: 289s

    max_load_factor(0.75), reserve(16):
    unordered_set: 239s
    unordered_map: 252s
*/

>>>>>>> origin/master
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
<<<<<<< HEAD
=======
//unordered_map<ull, bool> mp[26][26];
>>>>>>> origin/master
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
<<<<<<< HEAD
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

=======
    int start=clock();

//    for(int i = 0; i < 26; ++i)
//        for(int j = 0; j < 26; ++j) {
////            st[i][j].max_load_factor(0.75);
////            st[i][j].reserve(16);
//            mp[i][j].max_load_factor(0.75);
//            mp[i][j].reserve(16);
//        }

    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large-practice.out", "w", stdout);

>>>>>>> origin/master
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        init();
        cin >> L;
        for(int i = 0; i < L; ++i) {
            cin >> s;
            v[s.size()].push_back(s);
<<<<<<< HEAD
//            cout<<"   "<< s.size() <<endl;
//            cerr<<"   "<<s.size() << " " << s <<endl;
=======
>>>>>>> origin/master
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
<<<<<<< HEAD
        int ct=0;
=======

>>>>>>> origin/master
        for(int len = 1; len < 100005; ++len) {
            if(v[len].size()==0) continue;
            if(len > s.size()) break;

            ull r=0;
            for(int i = 0; i < len; ++i) r += p[s[i]-'a'];

            for(int i = 0; i < 26; ++i)
                for(int j = 0; j < 26; ++j)
                    st[i][j].clear();
<<<<<<< HEAD
            st[s[0]-'a'][s[len-1]-'a'].insert(r);
=======
//                    mp[i][j].clear();

            st[s[0]-'a'][s[len-1]-'a'].insert(r);
//            mp[s[0]-'a'][s[len-1]-'a'][r]=true;
>>>>>>> origin/master

            for(int i = 1; i+len-1 < s.size(); ++i) {
                r -= p[s[i-1]-'a'];
                r += p[s[len+i-1]-'a'];
                st[s[i]-'a'][s[i+len-1]-'a'].insert(r);
<<<<<<< HEAD
            }

            for(int i = 0; i < v[len].size(); ++i){
=======
//                mp[s[i]-'a'][s[i+len-1]-'a'][r]=true;
            }

            for(int i = 0; i < v[len].size(); ++i) {
>>>>>>> origin/master
                string& str = v[len][i];
                int a=str[0]-'a';
                int b=str[str.size()-1]-'a';
                ull c=has(str);
                if(st[a][b].find(c)!=st[a][b].end()) ++ans;
<<<<<<< HEAD
            }

            ct++;
            cerr << "len = " << len << " ct = " << ct << " num = " << v[len].size() << " s.size() = " << s.size() << endl;
        }
        cerr << ca << endl;
=======
//                if(mp[a][b].find(c)!=mp[a][b].end()) ++ans;
            }
        }
        int endd=clock();
        cerr << ca << "   " << (endd - start) / CLOCKS_PER_SEC << endl;
>>>>>>> origin/master
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}

