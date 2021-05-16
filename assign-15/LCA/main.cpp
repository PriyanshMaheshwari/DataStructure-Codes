#include <iostream>
#include <queue>
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

int LCA(BSTPTR T,int a,int b){
    if(a<T->data && b<T->data) LCA(T->lchild,a,b);
    else if(a>T->data && b>T->data) LCA(T->rchild,a,b);
    else return T->data ;
}

int main()
{
    BSTPTR T = NULL;
    cout << "Enter the values and press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(T,x);
    }

    cout << "Enter the numbers whose LCA you want to find." << endl;
    int a1,a2;
    cin >> a1 >> a2;

    cout << "LCA is : " << LCA(T,a1,a2);

    return 0;
}
