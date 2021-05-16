#include <iostream>
using namespace std;

struct dlnode;
typedef dlnode *DPTR;

struct dlnode{
    DPTR left;
    int data;
    DPTR right;
};

void addbegin(int x,DPTR &head){
    DPTR T = new dlnode;
    T->data = x;
    T->left = NULL;
    T->right = head;
    head = T;
}

void add(int x,DPTR &head){
    DPTR T1 = new dlnode;
    T1 = head;
    if(T1 == NULL){addbegin(x,head);return;}
    while(T1->right != NULL){T1 = T1->right;}
    DPTR T = new dlnode;
    T->data = x;
    T->right = NULL;
    T->left = T1;
    T1->right = T;
}

void printdl(DPTR head){
    if(head == NULL){return;}
    cout << head->data << " ";
    printdl(head->right);
}

void deletebegin(DPTR &head){
    DPTR T = head;
    head = T->right;
    T->right->left = NULL;
    delete(T);
}

void deleteend(DPTR &head){
    DPTR T = head;
    if(T->right == NULL){deletebegin(head);}
    while(T->right != NULL){T = T->right;}
    T->left->right = NULL;
    T->left = NULL;
    delete(T);
}

void del(int x,DPTR &head){
    DPTR T = head;
    if(head->data == x){deletebegin(head);return;}
    while(T->data != x){T = T->right;}
    if(T->right == NULL){deleteend(head);return;}
    T->left->right = T->right;
    T->right->left = T->left;
    delete(T);
}

struct dequeue{
    DPTR f;
    DPTR r;
};

void enqfront(int x,dequeue &q){
    if(q.f==NULL){addbegin(x,q.f);q.r=q.f;}
    else addbegin(x,q.f);
}

void defront(dequeue &q){
    if(q.f==NULL){cout << "Queue is empty." << endl;}
    else if(q.f==q.r){
        deletebegin(q.f);q.r = q.f;
    }
    else deletebegin(q.f);
}

void enqback(int x ,dequeue &q){
    if(q.f == NULL){addbegin(x,q.f);q.r=q.f;}
    else{
        DPTR T = new dlnode;
        T->data = x;
        T->right = NULL;
        T->left = q.r;
        q.r = T;
    }
}

void deback(dequeue &q){
    if(q.f==NULL){cout << "Queue is empty." << endl;}
    else if(q.f==q.r){
        deletebegin(q.f);q.r = q.f;
    }
    else{
        DPTR T = q.r;
        q.r = T->right;
        T->right->left = NULL;
        delete(T);
    }
}

int main()
{
    struct dequeue q;
    q.f = NULL;
    q.r = NULL;

}
