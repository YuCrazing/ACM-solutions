#include <bits/stdc++.h>
using namespace std;

struct Node {

    int value;
    Node * next;

    // assume all numbers are nonnegative
    Node(int _value = -1, Node * _next = NULL):value(_value), next(_next) {}

};

struct List {

    Node * head;

    bool debug;

    List(bool _debug = false) {
        head = new Node();
        debug = _debug;
    }

    ~List() {
        Node * cur = head->next, * nxt;
        while(cur != NULL) {
            nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void print() {
        Node * cur = head->next;
        printf("List: [");
        while(cur != NULL) {
            printf(cur->next==NULL?"%d":"%d ", cur->value);
            cur = cur->next;
        }
        printf("]\n");
    }

    void add(int _value) {

        if(debug) printf("Add %d.\n", _value);

        Node * cur = head;
        while(cur->next != NULL) cur = cur->next;
        cur->next = new Node(_value);

        if(debug) print();
    }

    void delete_first(int _value) {

        if(debug) printf("Delete first %d.\n", _value);

        Node * cur = head->next, * pre = head;
        while(cur != NULL && cur->value != _value) {
            cur = cur->next;
            pre = pre->next;
        }
        if(cur != NULL) {
            pre->next = cur->next;
            delete cur;
        }

        if(debug) print();
    }

    void delete_all(int _value) {

        if(debug) printf("Delete all %d.\n", _value);

        Node * cur = head->next, * pre = head;
        while(cur != NULL) {
            while(cur != NULL && cur->value != _value) {
                cur = cur->next;
                pre = pre->next;
            }
            if(cur == NULL) break;
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        }

        if(debug) print();
    }

    void unique() {

        if(debug) printf("Unique list.\n");

        Node * cur = head->next, * nxt;
        while(cur->next != NULL) {
            nxt = cur->next;
            if(nxt->value == cur->value) {
                cur->next = nxt->next;
                delete nxt;
            } else cur = cur->next;
        }

        if(debug) print();
    }

    // pos is 0 based;
    bool insert(int _value, int pos) {

        if(debug) printf("Insert %d at position %d.\n", _value, pos);

        if(pos >= 0) {
            Node * cur = head;
            while(cur != NULL) {
                if(pos == 0) {
                    cur->next = new Node(_value, cur->next);
                    break;
                }
                --pos;
                cur = cur->next;
            }

            if(debug) print();

            if(cur == NULL) return false;
            return true;
        }
    }
};



int main() {

//    list<int> lst0;
    List lst1(true);

    for(int i = 0; i < 5; ++i) {
        for(int j = 1; j < 3; ++j) {
            lst1.add(j);
            int x = rand()%5;
            lst1.add(x);
        }
    }

    for(int i = 0; i < 10; ++i) {
        int value = rand()%5;
        int pos = rand()%10;
        lst1.insert(value, pos);
    }

    lst1.add(4);
    lst1.add(4);

    lst1.unique();

    lst1.delete_first(1);
    lst1.delete_all(1);
    lst1.delete_all(2);
    lst1.delete_all(3);
    lst1.delete_all(4);
    lst1.delete_all(0);

    return 0;
}
