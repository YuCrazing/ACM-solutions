#include<bits/stdc++.h>
using namespace std;
char s[7][7][10] = {
    {
        "+-----+",
        "|    E|",
        "|     |",
        "|     |",
        "|     |",
        "|     |",
        "+-----+"
    },
    {
        "+-----+",
        "|-   E|",
        "|     |",
        "|     |",
        "|     |",
        "|     |",
        "+-----+"
    },
    {
        "+-----+",
        "|-   E|",
        "|--   |",
        "|     |",
        "|     |",
        "|     |",
        "+-----+"
    },
    {
        "+-----+",
        "|-  3G|",
        "|--   |",
        "|---  |",
        "|     |",
        "|     |",
        "+-----+"
    },
    {
        "+-----+",
        "|-  3G|",
        "|--   |",
        "|---  |",
        "|---- |",
        "|     |",
        "+-----+"
    },
    {
        "+-----+",
        "|-  4G|",
        "|--   |",
        "|---  |",
        "|---- |",
        "|     |",
        "+-----+"
    },
    {
        "+-----+",
        "|-  4G|",
        "|--   |",
        "|---  |",
        "|---- |",
        "|-----|",
        "+-----+"
    }
};

void print(int x) {
    for(int i = 0; i < 7; i++)
        printf("%s\n", s[x][i]);
}

int main() {
    int d;
    scanf("%d", &d);
    if(d >= 100) print(6);
    else if(d >= 90) print(5);
    else if(d >= 80) print(4);
    else if(d >= 60) print(3);
    else if(d >= 40) print(2);
    else if(d >= 20) print(1);
    else print(0);

    return 0;
}
