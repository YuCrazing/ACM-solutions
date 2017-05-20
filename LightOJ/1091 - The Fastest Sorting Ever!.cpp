#include<bits/stdc++.h>
using namespace std;

const int N = 7;
int n, T;

void print(vector<int> v) {
    string s;
    s += "void print(";

    for(int i = 0; i < n; i++) {
        s += "int ";
        s += (v[i] + 'a');
        s += ((i == n - 1) ? "" : ", ");
    }
    s += ")";
    s += "{ \nprintf(\"";
    for(int i = 0; i < n; i++) s += (i == n - 1) ? "%d\\n\"" : "%d ";
    for(int i = 0; i < n; i++) {
        s += ", ";
        s += (v[i] + 'a');
    }
    s += ");\n}";

    printf("%s\n", s.c_str());
}

void printFuncName(vector<int> v) {
    string s;
    s += "print(";
    for(int i = 0; i < n; i++) {
        s += (v[i] + 'a');
        s += ((i == n - 1) ? "" : ", ");
    }
    s += ");";
    printf("%s\n", s.c_str());
}

void dfs(vector<int> v, int cmp, int cur) {

    if(cur >= n) {
        printFuncName(v);
        return ;
    }

    if(cur == cmp) {
        dfs(v, 0, cur + 1);
        return;
    }

    string s;

    // v[cmp] < v[cur]
    s += "if(";
    s += (v[cmp] + 'a');
    s += '<';
    s += (v[cur] + 'a');
    s += ")";
    printf("%s\n", s.c_str());

    dfs(v, cmp + 1, cur);


    // else
    s = "else";
    printf("%s\n", s.c_str());

    int t = v[cur];
    for(int i = cur; i > cmp; i--) v[i] = v[i - 1];
    v[cmp] = t;
    dfs(v, 0, cur + 1);
}

vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        cin >> n;
        v.clear();
        for(int i = 0; i < n; i++) v.push_back(i);

        printf("Case %d:\n", ca);
        string s;
        print(v);
        s += "void sort(";
        for(int i = 0; i < n; i++) {
            s += "int ";
            s += (v[i] + 'a');
            s += ((i == n - 1) ? "" : ", ");
        }
        s += "){";
        printf("%s\n", s.c_str());
        dfs(v, 0, 0);
        printf("}\n");
    }

    return 0;
}
