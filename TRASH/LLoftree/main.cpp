#include <iostream>
using namespace std;

struct btnode{
    struct btnode* lchild;
    int data;
    struct btnode* rchild;
};

typedef struct btnode* BSTPTR;

void add(BSTPTR &T,int k){
    if(T == NULL){
        BSTPTR temp = new struct btnode;
        temp->data = k;
        temp->lchild = NULL;
        temp->rchild = NULL;
        T = temp;
    }
    else if(T->data > k){add(T->lchild,k);}
    else add(T->rchild,k);
}

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

struct lnode{
    BSTPTR T;
    struct lnode *next;
};

typedef struct lnode *LPTR;

void addbegin(LPTR &L){
    LPTR T1;
    T1 = new struct lnode;
    T1->T = NULL;
    T1->next = L;
    L = T1;
}

void add(LPTR &L){
    if(L == NULL){addbegin(L);return;}
    LPTR T2;
    T2 = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T2->next = NULL;
    T2->T = NULL;
    T1->next = T2;
}

int main()
{
    LPTR L = NULL;
    return 0;
}
