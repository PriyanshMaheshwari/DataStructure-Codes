#include <bits/stdc++.h>
using namespace std;

struct bstnode{
    struct bstnode *lchild;
    int data;
    char c;
    bstnode *rchild;
};

typedef struct bstnode *BSTPTR;

BSTPTR getnode(int k,char l){
    BSTPTR temp = new bstnode;
    temp->data = k;
    temp->c = l;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void add(BSTPTR &T,char y,int x){
    if(T == NULL){
        T = getnode(x,y);
        return;
    }
    if(int(T->c) > int(y)) add(T->lchild,y,x);
    else add(T->rchild,y,x);
}

void heapify(BSTPTR &T,char y){
    if(int(y) < int(T->c)) heapify(T->lchild,y);
    else if(int(y) > int(T->c)) heapify(T->rchild,y);
    if(T->lchild && T->lchild->data>T->data){
        BSTPTR k1 = T,k2 = T->lchild;
        k1->lchild = k2->rchild;
        k2->rchild = k1;
        T = k2;
    }
    else if(T->rchild && T->rchild->data>T->data){
        BSTPTR k1 = T,k2 = T->rchild;
        k1->rchild = k2->lchild;
        k2->lchild = k1;
        T = k2;
    }
}

void pre(BSTPTR T){
    if(T == NULL) return;
    cout << T->data << " " << T->c << "   " ;
    pre(T->lchild);
    pre(T->rchild);
}

int main(){

    BSTPTR T = NULL;
    cout << "Enter the char and then number and press $ to exit." << endl;
    while(1){
        int x;char y;
        cin >> y >> x;
        if(y == '$') break;
        add(T,y,x);
        heapify(T,y);
    }

    pre(T);

    return 0;
}
