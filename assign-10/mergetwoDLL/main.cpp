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

void rev(DPTR &head,DPTR &t){
    if(t->right == NULL){head = t;}
    DPTR temp = t->right;
    t->right = t->left;
    t->left = temp;
    if(t->left == NULL){return;}
    rev(head,t->left);
}

void create(DPTR L1,DPTR L2,DPTR &L3){
    if(L1 == NULL && L2 == NULL){return;}
    else if(L1==NULL){add(L2->data,L3);create(L1,L2->right,L3);}
    else if(L2==NULL){add(L1->data,L3);create(L1->right,L2,L3);}
    else{
        if(L1->data < L2->data){
            add(L1->data,L3);
            create(L1->right,L2,L3);
        }
        else{
            add(L2->data,L3);
            create(L1,L2->right,L3);
        }
    }
}

int main(){

    DPTR L1 = NULL;
    DPTR L2 = NULL;
    cout << "Enter the entries of first DLL and press -1 to break." << endl;
    while(1){
        int x;cin>>x;
        if(x == -1){break;}
        add(x,L1);
    }
    cout << "Enter the entries of second DLL and press -1 to break." << endl;
    while(1){
        int x;cin>>x;
        if(x == -1){break;}
        add(x,L2);
    }

    DPTR L3 = NULL;
    create(L1,L2,L3);
    printdl(L3);

    return 0;
}
