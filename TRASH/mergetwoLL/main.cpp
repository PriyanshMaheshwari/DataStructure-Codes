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

void mer(LPTR &L1,LPTR &L2){
    if(L2 == NULL) return;
    if(L1->next == NULL){
        L1->next = L2;
        return;
    }
    if(L1->next->data < L2->data){
        mer(L1->next,L2);
    }
    else if(L1->next->data > L2->data){
        LPTR temp = L2;
        L2 = L2->next;
        temp->next = L1->next;
        L1->next = temp;
        mer(L1,L2);
    }
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
    cout << mid(L1);
    cout << "Enter the entries of second LL and press -1 to break." << endl;
    while(1){
        int x;cin>>x;
        if(x == -1){break;}
        add(x,L2);
    }
    LPTR T;
    if(L1->data < L2->data){
        T = L1;mer(L1,L2);
    }
    else{
        T = L2;mer(L2,L1);
    }

    printl(T);

    return 0;
}
