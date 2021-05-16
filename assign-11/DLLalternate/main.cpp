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

int cnt(DPTR &L){
    static int i = 0;
    if(L==NULL){return i;}
    else{i++;return cnt(L->right) ;}
}

void create(DPTR &head){
    DPTR L = head;
    while(L->right != NULL){L = L->right;}
    DPTR T = head;
    int n = cnt(head);
    if(n%2 == 0){n = n/2-1;}
    else{n = n/2;}
    for(int i=0;i<n;i++){
        DPTR temp = L->left;
        L->left = T;
        L->right = T->right;
        T->right->left = L;
        T->right = L;
        temp->right = NULL;
        L = temp;
        T = T->right->right;
    }
}

int main()
{
    DPTR head = NULL;
    cout << "Enter the values of DLL and press -1 to break." << endl;
    while(1){
        int x;cin >>x;
        if(x==-1){break;}
        add(x,head);
    }
    create(head);
    printdl(head);

    return 0;
}
