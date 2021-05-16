#include <iostream>
#include <stack>
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

int main(){

    BSTPTR T = NULL;
    cout << "Enter the values and press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(T,x);
    }
    inorderprint(T);
    cout << endl;

    stack<BSTPTR> S;
    S.push(T);
    BSTPTR temp = T;
    do{
        while(temp != NULL){ S.push(temp);temp = temp->lchild;}
        temp = S.top();
        S.pop();
        cout << temp->data << " ";
        temp=temp->rchild;
    }
    while(temp!=NULL || !S.empty());

    return 0;
}
