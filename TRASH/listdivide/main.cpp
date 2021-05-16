#include <iostream>
using namespace std;

struct lnode{
    int data;
    char c;
    lnode *next;
};

struct dlnode{
    dlnode* left;
    char ch;
    dlnode* right;
};

struct lnode2{
    int data;
    lnode2 *nex;
};

struct bst{
    bst *lchild;
    char cha;
    lnode2 *ptr;
    bst* rchild;
};

typedef lnode *LPTR;

void addbegin(int x,char ch,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;T->c = ch;
    T->next = L;
    L = T;
}

void add(int x,char ch,LPTR &L){
    if(L == NULL){addbegin(x,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->data = x;T->c = ch;
    T1->next = T;
    T->next = NULL;
}

void deletebegin(LPTR &L){
    L = L->next;
}

void del(int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    if(T1->data == y){deletebegin(L);return;}
    while(T1->next->data != y){T1 = T1->next ;}
    T = T1->next;
    T1->next = T->next;
    delete(T);
}


int main()
{
    LPTR L = NULL;
    cout << "Enter the values and press -1 to end" << endl;
    while(1){
        int x;char c;
        cin >> c >> x;
        if(x == -1) break;
        add(x,c,L);
    }

    lnode2 *C;
    bst* B;
    dlnode *S;

    LPTR T = L;
    while(T!=NULL){

    }

    return 0;
}
