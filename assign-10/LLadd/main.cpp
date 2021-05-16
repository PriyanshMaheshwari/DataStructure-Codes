#include <iostream>
#include <cmath>
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

void ad(LPTR &L1,LPTR &L2,int car,LPTR &res){
    if(L1 == NULL) return;
    ad(L1->next,L2->next,car,res);
    int sum=L1->data+L2->data+car;
    car = sum/10;
    sum = sum%10;
    addbegin(sum,res);
}

int main(){
    LPTR L1 = NULL;
    LPTR L2 = NULL;
    cout << "Enter the entries of first LL and press -1 to break." << endl;
    while(1){
        int x;cin>>x;
        if(x == -1){break;}
        add(x,L1);
    }
    cout << "Enter the entries of second LL and press -1 to break." << endl;
    while(1){
        int x;cin>>x;
        if(x == -1){break;}
        add(x,L2);
    }

    LPTR res = NULL;
    /*LPTR L3 = NULL;
    int a1 = 0;
    int x = cnt(L1);
    int i = x-1;

    LPTR T = new lnode;
    T = L1;
    while(i>=0){
        int y = T->data;
        a1 += y*pow(10,i);
        T = T->next;
        i--;
    }
    int a2=0;
    T = L2;
    int y = cnt(L2) - x;
    i = y-1;
    while(i>=0){
        int y = T->data;
        a2 += y*pow(10,i);
        T = T->next;
        i--;
    }
    a1 += a2;
    if(x%2 != 0){a1 += 2;}
    while(a1>0){
        addbegin(a1%10,L3);
        a1 /= 10;
    }
    printl(L3);*/

    ad(L1,L2,0,res);
    printl(res);

    return 0;
}
