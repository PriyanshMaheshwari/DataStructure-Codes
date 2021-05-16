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
    LPTR s = NULL;
    s = new struct lnode;
    s = L;
    LPTR f = NULL;
    f = L;
    while(f->next != NULL && f->next->next != NULL){
        s = s->next;f = f->next->next;
    }
    return s->data;
}

int main()
{
    LPTR L = NULL;
    cout << "Enter the linked list and -1 to enter." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(x,L);
    }
    cout << "Add it to the which node or -1 to not do it?" << endl;
    int a;cin >> a;

    if(a!=-1){
        LPTR X = new struct lnode;
        X = L;
        while(X->next != NULL){X = X->next;}
        LPTR X2 = new struct lnode;
        X2 = L;
        while(X2->data!=a){X2 = X2->next;}
        X->next = X2;
    }

    LPTR s = NULL;
    LPTR f = NULL;
    s= L;f= L;
    int flag = 1;
    while(s!=f || flag==1){
        if(f==NULL || f->next==NULL){break;}
        flag = 0;
        s = s->next;f = f->next->next;
    }
    if(f!=NULL && f->next!=NULL){cout << "YES" << endl;}
    else{cout << "NO" << endl ;return 0;}

    s = L;
    while(s!=f){
        s = s->next;
        f = f->next;
    }
    LPTR Y = new struct lnode;
    Y = s;
    cout << "Start of loop : " << s->data << endl;

    while(f->next != s){f = f->next;}
    f->next = NULL;

    cout << "List after clearing loop." << endl;
    printl(L);

    return 0;
}
