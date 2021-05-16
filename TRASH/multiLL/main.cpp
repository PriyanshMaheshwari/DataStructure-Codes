#include <bits/stdc++.h>
using namespace std;

typedef struct lnode{
    string data;
    struct lnode* dlink;
    struct lnode* next;
}* LPTR;

void addbegin(string x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;T->dlink = NULL;
    T->next = L;
    L = T;
}

void add(string x,LPTR &L){
    if(L == NULL){addbegin(x,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->data = x;T->dlink = NULL;
    T1->next = T;
    T->next = NULL;
}

void create(LPTR &L){
    cout << "Enter the data." << endl;
    string x;cin >> x;
    if(x == "$") return;
    add(x,L);
    cout << "Do you want branch?" << endl;
    int y;cin >> y;
    if(y == 1) create(L->dlink);
    create(L->next);
}

void print(LPTR L){
}

int main(){
    LPTR L = NULL:
    return 0;
}
