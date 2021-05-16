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

void checkrev(DPTR L3,DPTR L2,int &f){
    static DPTR L1 = L3;
    if(L2->right != NULL) checkrev(L3,L2->right,f);
    if(f == -1) return;
    if(L1->data != L2->data || (L2 && !L1) || (!L2 && L1)) f = -1;
    L1 = L1->right;
}

int main()
{
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

    int f = 0;
    checkrev(L1,L2,f);
    if(f == -1) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
