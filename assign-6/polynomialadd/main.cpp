#include <iostream>
using namespace std;

struct lnode{
    int coeff;
    int exp;
    struct lnode *next;
};

typedef struct lnode *LPTR;

void addbegin(int x,int e,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->coeff = x;
    T->exp = e;
    T->next = L;
    L = T;
}



void add(int x,int e,LPTR &L){
    if(L == NULL){addbegin(x,e,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->coeff = x;
    T->exp = e;
    T1->next = T;
    T->next = NULL;
}

void printl(LPTR &L){
    LPTR T;
    T = new struct lnode;
    T = L;
    while(T!=NULL){
        cout << T->coeff << " " << T->exp << endl;
        T = T->next;
    }
}

void deletebegin(LPTR &L){
    L = L->next;
}

void del(int x,int e,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    if(T1->coeff == x && T1->exp == e){deletebegin(L);return;}
    while(T1->next->coeff != x && T1->next->exp != e){T1 = T1->next ;}
    T = T1->next;
    T1->next = T->next;
    delete(T);
}

int searc(int e,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T = L;
    if(L==NULL){return 0;}
    else if(T->exp == e){return 1;}
    else{return searc(e,L->next);}
}

int main(){
    LPTR L1 = NULL;
    LPTR L2 = NULL;
    cout << "Enter the entries of first polynomial and press -1 and -1 to break." << endl;
    while(1){
        int x,y;cin>>x>>y;
        if(x == -1 && y == -1){break;}
        add(x,y,L1);
    }
    cout << "Enter the entries of second polynomial and press -1 and -1 to break." << endl;
    while(1){
        int x,y;cin>>x>>y;
        if(x == -1 && y == -1){break;}
        add(x,y,L2);
    }

    LPTR T1,T2;
    T1 = new struct lnode;
    T2 = new struct lnode;
    T1 = L1;T2 = L2;

    LPTR poly = NULL;

    while(T1!=NULL && T2!=NULL){
        if(T1->exp < T2->exp){
            add(T1->coeff,T1->exp,poly);
            T1 = T1->next;
        }
        else if (T2->exp < T1->exp){
            add(T2->coeff,T2->exp,poly);
            T2 = T2->next;
        }
        else{
            int x = T1->coeff+T2->coeff;
            add(x,T1->exp,poly);
            T1 = T1->next;
            T2 = T2->next;
        }
    }

    if(T1 != NULL){
        while(T1 != NULL){
            add(T1->coeff,T1->exp,poly);
            T1 = T1->next;
        }
    }

    if(T2 != NULL){
        while(T2 != NULL){
            add(T2->coeff,T2->exp,poly);
            T2 = T2->next;
        }
    }

    printl(poly);

    return 0;
}
