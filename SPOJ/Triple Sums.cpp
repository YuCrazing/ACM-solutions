/*
    [f(x)^3 - 3*f(x^2)*f(x) + 2*f(x^3)]/6
*/

#include<bits/stdc++.h>
using namespace std;

const int N=2e5;
const double PI=acos(-1.0);

struct Complex {
    double x, y;
    Complex(double _x=0.0, double _y=0.0):x(_x),y(_y) {}
    Complex operator-(const Complex &b)const {
        return Complex(x-b.x, y-b.y);
    }
    Complex operator+(const Complex &b)const {
        return Complex(x+b.x, y+b.y);
    }
    Complex operator*(const Complex &b)const {
        return Complex(x*b.x-y*b.y, x*b.y+y*b.x);
    }
};

void change(Complex y[], int len) {
    int i, j, k;
    for(int i = 1, j=len/2; i < len-1; i++) {
        if(i<j) swap(y[i], y[j]);
        k=len/2;
        while(j>=k) {
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}

void fft(Complex y[], int len, int on) {
    change(y, len);
    for(int h=2; h <= len; h <<= 1) {
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for(int j = 0; j < len; j+=h) {
            Complex w(1, 0);
            for(int k = j; k < j+h/2; k++) {
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
        for(int i = 0; i < len; i++)
            y[i].x /= len;
}

int a[N];
Complex x1[N], x2[N], x3[N];
int main() {
    int n, x, mx=-1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        x+=20000;
        a[x]++;
        mx=max(mx, x);
    }

    mx++;
    int len=1;
    while(len < mx*3) len <<= 1;

    for(int i = 0; i < len; i++) x1[i]=x2[i]=x3[i]=Complex(0, 0);
    for(int i = 0; i < mx; i++) {
        x1[i]=Complex(a[i], 0.0);
        x2[i+i]=Complex(a[i]*a[i], 0.0);
        x3[i+i+i]=Complex((double)(a[i]*a[i]*a[i]), 0.0);
    }

    fft(x1, len, 1);
    fft(x2, len, 1);
    fft(x3, len, 1);
    for(int i = 0; i < len; i++) x1[i]=x1[i]*x1[i]*x1[i]-Complex(3.0, 0.0)*x2[i]*x1[i]+Complex(2.0, 0.0)*x3[i];
    fft(x1, len, -1);

    for(int i = 0; i < len; i++) if((int)(x1[i].x+0.5)) printf("%d : %d\n", i-20000*3, (int)(x1[i].x+0.5)/6);

    return 0;
}
