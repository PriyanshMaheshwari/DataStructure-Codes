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
    if(L == NULL){addbegin(x,L);return;}
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

int mid(LPTR &L){
    LPTR s = new struct lnode;
    s = L;
    LPTR f = L;
    while(f->next != NULL && f->next->next != NULL){
        s = s->next;f = f->next->next;
    }
    return s->data;
}

void create(LPTR L1,LPTR L2,LPTR &L3){
    if(L1 == NULL && L2 == NULL){return;}
    else if(L1==NULL){add(L2->data,L3);create(L1,L2->next,L3);}
    else if(L2==NULL){add(L1->data,L3);create(L1->next,L2,L3);}
    else{
        if(L1->data < L2->data){
            add(L1->data,L3);
            create(L1->next,L2,L3);
        }
        else{
            add(L2->data,L3);
            create(L1,L2->next,L3);
        }
    }
}

void insertionsort(LPTR &L,LPTR &L2){
    if(L2 == NULL){return;}
    if(L->next == L2){L->next = NULL;}
    LPTR T = L2;
    L2 = L2->next;
    LPTR T2 = L;
    if(T2->data > T->data){
        T->next = L;
        L = T;
    }
    else{
        while(T2->next!=NULL && T2->next->data<T->data){
            T2 = T2->next;
        }
        T->next = T2->next;
        T2->next = T;
    }
    insertionsort(L,L2);
}

int main()
{
    LPTR L = NULL;
    cout << "Enter the entries of LL and press -1 to break." << endl;
    while(1){
        int x;cin>>x;
        if(x == -1){break;}
        add(x,L);
    }

    LPTR L2 = L->next;
    insertionsort(L,L2);
    printl(L);

    return 0;
}
