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


class node {
public:
    int data;
    node*next ;
    node(int n) {
        this->data = n;
        next = NULL;
    }
};

void insertTail(node*&h, int d) {
    if (h == NULL) {
        h = new node(d);
        h->next = h;
        return;
    }

    node*t = h;
    while (t->next != h)t = t->next;

    t->next = new node(d);
    t->next->next = h;

    return;
}

void printt(node*h) {
    node*t = h;
    while (t->next != h) {
        cout << t->data << " ";
        t = t->next;
    } cout << t->data << endl;

    return;
}

void insertHead(node*&h, int d) {

    if (h == NULL) {
        node*t = new node(d);
        h = t;
        h->next = h;
        return;
    }

    node*t = h;
    node*newNode = new node(d) ;

    newNode->next = h;
    while (t->next != h)t = t->next;

    t->next = newNode;
    h = newNode;
    return;
}

void insertAt(node*&h, int pos, int v) {

    if ( pos == 1 ) {
        node*t = new node(v);
        node*ptr = h;
        while (ptr->next != h)ptr = ptr->next ;
        ptr->next = t;
        t->next = h;
        h = t;
        return;
    }

    int i = 1;
    node*ptr = h;
    pos -= 2;
    while (i <= pos) {
        ptr = ptr->next;
        i++;
    }
    node*nextt = ptr->next;
    ptr->next = new node(v);
    ptr->next->next = nextt;

    return;
}

int main() {
    io();

    node*h = NULL;
    for (int i = 0; i < 7; ++i) {
        insertTail(h, 11 + i);
    }

    // insertTail(h, 19);
    insertAt(h, 2, -12);
    printt(h);



    return 0;
}
