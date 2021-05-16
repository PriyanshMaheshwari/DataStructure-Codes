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

int main(){
    LPTR L1 = NULL;
    LPTR L2 = NULL;
    cout << "Enter the pre values of L1 and the L2 and then after values." << endl;
    int a,b,c;
    cin >> a >> b >> c;
    cout << "Enter pre L1 values - ";
    for(int i=0;i<a;i++){
        int x;
        cin >> x;
        add(x,L1);
    }
    cout << "For L2 - " ;
    for(int i=0;i<b;i++){
        int x;
        cin >> x;
        add(x,L2);
    }
    cout << "Common values - ";
    LPTR L3 = NULL;
    for(int i=0;i<c;i++){
        int x;
        cin >> x;
        add(x,L3);
    }

    LPTR T1 = new struct lnode;
    T1 = L1;
    while(T1->next != NULL){T1 = T1->next;}
    T1->next = L3;
    LPTR T2 = new struct lnode;
    T2 = L2;
    while(T2->next != NULL){T2 = T2->next;}
    T2->next = L3;

    // Real code starts here.
    int cnt1 = cnt(L1);
    int cnt2 = cnt(L2)-cnt1;

    LPTR Ta = new struct lnode;
    Ta = L1;
    LPTR Tb = new struct lnode;
    Tb = L2;

    if(cnt1 > cnt2){
        for(int i=0;i<cnt1-cnt2;i++){Ta = Ta->next;}
    }
    else{
        for(int i=0;i<(cnt2-cnt1);i++){Tb = Tb->next;}
    }

    while(Ta->data != Tb->data){
        Ta = Ta->next;
        Tb = Tb->next;
    }

    cout << "Merge point : " << Ta->data;

    return 0;
}
