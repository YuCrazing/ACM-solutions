#include <cstdio>
#include <cstring>
using namespace std;

char s[333], ch, in[333];
int main() {
    int l = 0;
    gets(in);
    int sz = strlen(in);
    for(int i = 0; i < sz; ) {
        ch = in[i];
        if(ch == ' ') {
            s[l ++] = ch;
            while((ch = in[++ i]) ==  ' ') {}
            if(i >= sz) break;
            s[l ++] = ch;

        } else {
            s[l ++] = ch;
        }
        i ++;
    }
    if(s[l - 1] == '\n') s[l - 1] = '\0';
    else s[l ++] = '\0';
    printf("%s\n", s);
    return 0;
}
