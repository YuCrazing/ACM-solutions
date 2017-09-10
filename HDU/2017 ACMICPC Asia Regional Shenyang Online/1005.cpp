#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

const int N=2;

//void add(ll &a, ll b){
//
//}

struct Matrix {
    int n;
    ll m[N][N];

    Matrix(int _n, ll _k=0):n(_n) {
        memset(m, 0, sizeof(m));
        if(_k) for(int i = 0; i < N; i++) m[i][i]=1;
    }

    Matrix operator*(const Matrix &b)const {
        Matrix c(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++) {
                    c.m[i][j] += m[i][k]*b.m[k][j]%mod;
                    c.m[i][j] %= mod;
                }

        return c;
    }

    Matrix operator^(ll x)const {
        Matrix res(n, 1);
        Matrix a=*this;
        while(x) {
            if(x&1) res=res*a;
            a=a*a;
            x>>=1;
        }
        return res;
    }
};

int main() {
    ll k;
    Matrix a(2);
    while(scanf("%lld",&k)!=EOF) {
        a.m[0][0]=1;
        a.m[0][1]=1;
        a.m[1][0]=1;
        a.m[1][1]=0;
        a=a^(2*k+2);
//        printf("%lld %lld\n")
        printf("%lld\n", (a.m[0][0]-1+mod)%mod);
    }
    return 0;
}
