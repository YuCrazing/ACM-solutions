#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 50 + 5;
const int CHARS = 26;

struct Node
{
    int son[CHARS], next, cnt;
};

struct AC
{
    Node node[N];
    int tol, n, pos[1011];
    stack<int> st;
    string word[1011], text;

    int newNode()
    {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].cnt = 0;
        return tol++;
    }

    void init()
    {
        tol = 0;
        newNode();
    }

    void insert(string& s, int index)
    {
        int l = s.size(), cur = 0;
        for(int i = 0; i < l; i++)
        {
            int& son = node[cur].son[s[i] - 'A'];
            if(!son) son = newNode();
            cur = son;
        }
        pos[index] = cur;
    }

    void bfs()
    {
        queue<int> q;
        for(int i = 0; i < CHARS; i++) if(node[0].son[i]) q.push(node[0].son[i]);
        while(!q.empty())
        {
            int fa = q.front();
            q.pop();
            for(int i = 0; i < CHARS; i++)
            {
                int& son = node[fa].son[i];
                int next = node[fa].next;
                if(!son)
                {
                    son = node[next].son[i];
                    continue;
                }
                node[son].next = node[next].son[i];
                q.push(son);
                st.push(son);
            }
        }
    }

    void search(string & s)
    {
        int l = s.size(), cur = 0;
        for(int i = 0; i < l; i++)
        {
            if(s[i] < 'A' || s[i] > 'Z')
            {
                cur = 0;
                continue;
            }
            cur = node[cur].son[s[i] - 'A'];
            node[cur].cnt ++;
        }
        while(!st.empty())
        {
            int fa = st.top();
            int next = node[fa].next;
            st.pop();
            node[next].cnt += node[fa].cnt;
        }
    }

    void read()
    {
        for(int i = 0; i < n; i++)
        {
            cin >> word[i];
            insert(word[i], i);
        }
    }

    void print()
    {
        for(int i = 0; i < n; i++)
        {
            if(node[pos[i]].cnt)
            {
                cout << word[i] << ": " << node[pos[i]].cnt << endl;
            }
        }
    }

    void gao()
    {
        init();
        read();
        bfs();
        cin >> text;
        search(text);
        print();
    }
} ac;

int main()
{

    ios::sync_with_stdio(false);

    while(cin >> ac.n)
    {
        ac.gao();
    }

    return 0;
}
