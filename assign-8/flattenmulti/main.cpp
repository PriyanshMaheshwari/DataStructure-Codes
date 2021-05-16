#include <iostream>
using namespace std;

struct lnode{
    int data;
    struct lnode *dlink;
    struct lnode *next;
};

typedef struct lnode *LPTR;

void addbegin(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->next = L;
    T->dlink = NULL;
    L = T;
}

void addbegindlink(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->dlink = L;
    T->next = NULL;
    L = T;
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
    T->dlink = NULL;
}

void adddlink(int x,LPTR &L){
    if(L == NULL){addbegindlink(x,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->data = x;
    T1->dlink = T;
    T->dlink = NULL;
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

int main()
{
    LPTR L = NULL;
    while(1){
      cout << "Enter the entry." << endl;
      int x;cin >> x;
      if(x == -1){break ;}
      add(x,L);
      cout << "Do u want to add a lower link press -1 to end." << endl;
      LPTR X = new struct lnode;
      X = L;
      while(X->next != NULL){X = X->next;}
      while(1){
          int y;cin >> y;
          if(y == -1){break;}
          adddlink(y,X->dlink);
          X = X->dlink;
      }
    }
    LPTR L2 = NULL;

    LPTR T = new lnode;
    T = L;
    while(T!=NULL){
        add(T->data,L2);
        LPTR T2 = new lnode;
        T2 = T->dlink;
        while(T2 != NULL){
            add(T2->data,L2);
            T2 = T2->dlink;
        }
        T = T->next;
    }

    printl(L2);

    return 0;
}
