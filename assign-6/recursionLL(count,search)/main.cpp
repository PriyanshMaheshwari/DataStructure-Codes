#include <iostream>
using namespace std;

struct lnode{
    int data;
    struct lnode *next;
};

typedef struct lnode *LPTR;

void addbegin(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->next = L;
    L = T;
}

void addafter(int x,int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->data != y){T1 = T1->next ;}
    T->data = x;
    T->next = T1->next;
    T1->next = T;
}

void addbefore(int x,int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    if(T1->data == y){addbegin(x,L);return;}
    while(T1->next->data != y){T1 = T1->next ;}
    T->data = x;
    T->next = T1->next;
    T1->next = T;
}

void add(int x,LPTR &L){
    if(L == NULL){addbegin(x,L);}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->data = x;
    T1->next = T;
    T->next = NULL;
}

void printl(LPTR &L){
    LPTR T;
    T = new struct lnode;
    T = L;
    while(T!=NULL){
        cout << T->data << " ";
        T = T->next;
    }
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

int cnt(LPTR &L){
    static int i = 0;
    if(L==NULL){return i;}
    else{i++;return cnt(L->next) ;}
}

int searc(int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T = L;
    if(L==NULL){return 0;}
    else if(T->data == y){return 1;}
    else{return searc(y,L->next);}
}

int main()
{
    LPTR L = NULL;
    addbegin(5,L);
    addafter(8,5,L);
    addafter(2,8,L);
    add(9,L);
    printl(L);
    cout << endl << cnt(L) << endl ;
    cout << searc(6,L) << endl;
    cout << searc(8,L) << endl;
    return 0;
}
