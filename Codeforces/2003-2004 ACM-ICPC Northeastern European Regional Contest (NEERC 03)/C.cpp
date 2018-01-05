#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
char s[N];
int ind=0;
bool nl=true, fi=true;
void add(int ad) {
    ind+=ad;
    if(ind<0) ind++;
}

void tab() {
    for(int i = 0; i < ind*4; i++) printf(" ");
}

void newline() {
    nl=true;
    //printf("%c%c", 13, 10);
    printf("\n");
}

void put(char ch) {
    switch (ch) {
    case ',':
        if(nl) {
            tab();
            nl=false;
        }
        printf(", ");
        //newline();
        break;
    case '{':
        add(1);
        if(fi) {
            printf("{");
            fi=false;
        } else {

            printf(" {");
        }
        newline();
        break;
    case ';':
        if(nl) {
            tab();
            nl=false;
        }
        printf(";");
        newline();
        break;
    case '}':
        add(-1);
        if(!nl) newline();
        if(nl) {
            tab();
            nl=false;
        }
        printf("}");
        break;
    default:
        if(nl) {
            tab();
            nl=false;
        }
        printf("%c", ch);
        break;
    }
}

bool ok[127];

void init() {
    ind=0;
    for(int i = 0; i < 10; i++) ok[i+'0']=true;
    for(int i = 0; i < 26; i++) ok[i+'a']=true;
    for(int i = 0; i < 26; i++) ok[i+'A']=true;
    ok['{']=true;
    ok['}']=true;
    ok['(']=true;
    ok[')']=true;
    ok[',']=true;
    ok[';']=true;
}

char getNext() {
    int ch=0;
    while(1) {
        ch=getchar();
        if(ch==-1) return 0;
        if(ok[ch]) return ch;
    }
}

int main() {
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    init();
    while(1) {
        char ch=getNext();
        if(ch==0) break;
        if(!ok[ch]) continue;
        //if(ch=='}') add(-1);
        //if(nl) tab();
        put(ch);
    }
    return 0;
}
