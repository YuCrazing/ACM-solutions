#include<bits/stdc++.h>
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if(k%2==0){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) cout << ".";
        cout << endl;
        for(int j = 0; j < 2; ++j){
            cout << ".";
            for(int i = 0; i < k/2; ++i) cout <<"#";
            for(int i = 0; i < n-1-k/2; ++i) cout <<".";
            cout << endl;
        }
        for(int i = 0; i < n; i++) cout << ".";
        cout << endl;
    }else if(n%2==1){
        cout << "YES" << endl;

        for(int i = 0; i < n; i++) cout << ".";
        cout << endl;

        if(k > n-2){
//            cout << "NO" << endl;
            cout << ".";
            for(int i = 0; i < n-2; ++i) cout <<"#";
            cout << "." << endl;
            k-=n-2;
            for(int i = 0; i < (n-k)/2; ++i) cout << ".";
            for(int i = 0; i < k/2; ++i) cout <<"#";
            cout <<".";
            for(int i = 0; i < k/2; ++i) cout <<"#";
            for(int i = 0; i < (n-k)/2; ++i) cout << ".";
            cout << endl;
        }
        else{
            for(int i = 0; i < (n-k)/2; ++i) cout << ".";
            for(int i = 0; i < k; ++i) cout <<"#";
            for(int i = 0; i < (n-k)/2; ++i) cout << ".";
            cout << endl;
            for(int i = 0; i < n; i++) cout << ".";
            cout << endl;
        }

        for(int i = 0; i < n; i++) cout << ".";
        cout << endl;
    }
    else cout << "NO" << endl;
}

