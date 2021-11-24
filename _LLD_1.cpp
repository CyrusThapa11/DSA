#include <bits/stdc++.h>
using namespace std;

void io() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}


class dnode {
public:
    int data;
    dnode*next , *prev;
    dnode(int n) {
        this->data = n;
        prev = NULL;
        next = NULL;
    }
};

void atHead( dnode*&h, int d) {
    if (h == NULL) {
        h = new dnode(d);
        return;
    }

    dnode*t = new dnode(d);

    t->next = h;
    h->prev = t;
    h = t;

    return;
}

void printt(dnode*h) {
    dnode*t = h;
    while (t->next != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << t->data << endl;
    return;
}

void printRev( dnode*h ) {
    dnode*t = h;
    while (t->next != NULL)t = t->next;

    while ( t->prev != NULL  ) {
        cout << t->data << " ";
        t = t->prev;
    }
    cout << t->data << endl;
    return;
}

void afterNode(dnode*&h, int d , int val) {
    dnode*t = h;

    while ( t != NULL && t->data != d) {
        t = t->next;
    }

    if (t == NULL) {
        cout << "not present " << endl;
        return;
    }

    dnode*t2 = new dnode(val);
    t2->next = t->next;

    if (t->next == NULL) {

    } else
        t->next->prev = t2;

    t->next = t2;
    t2->prev = t;

    return;
}

void beforeNode(dnode*&h, int d, int val ) {
    dnode*t = h;

    if (h->data == d) {
        dnode*t2 = new dnode(val);
        t2->next = h;
        h->prev = t2;
        h = t2;
        return;
    }

    while ( t ->next != NULL && t->next->data != d) {
        t = t->next;
    }

    if (t->next == NULL) {
        cout << "not present " << endl;
        return;
    }

    dnode*t2 = new dnode(val);
    t2->next = t->next;
    // if (t->next == NULL) {}
    // else
    t->next->prev = t2;

    t->next = t2;
    t2->prev = t;

    return;
}

void delNode(dnode*&h, int d) {
    if (h->data == d) {
        dnode*t = h->next;
        delete(h);
        h = t;
        return;
    }
    dnode*t = h;
    while (t != NULL && t->data != d) {
        t = t->next;
    }
    dnode*prev = t->prev;
    dnode*nextt = t->next;
    delete(t);

    prev->next = nextt;
    if (nextt != NULL)
        nextt->prev = prev;

    return;
}

int main() {
    io();

    dnode*h = NULL;
    for (int i = 0 ; i < 8 ; i++) {
        atHead(h, i + 19);
    }

    printt(h);
    // printRev(h);

    // afterNode(h, 19, 100);
    // beforeNode(h, 19, 110);
    delNode(h, 26);
    printt(h);

    return 0;
}
