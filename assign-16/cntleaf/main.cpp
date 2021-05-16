#include <iostream>

using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

int pass(int i,char c,char b[],int n){
    int j = i+1;
    while(j<=n ){
        if(b[j] == c) return j;j++;
    }
}

BTPTR create(char a[],char b[],int n,int i){
    static int k = 0;
    if(i>n) return NULL;
    BTPTR temp = new btnode;
    temp->data = a[k++];
    temp->lchild = temp->rchild = NULL;
    if(i==n) return temp;
    int x = pass(i,temp->data,b,n);
    temp->lchild = create(a,b,x-1,i);
    temp->rchild = create(a,b,n,x+1);
    return temp;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

int cntleaf(BTPTR T){
    if(T==NULL) return 0;
    else if(T->lchild==NULL && T->rchild==NULL) return 1;
    else return cntleaf(T->lchild)+cntleaf(T->rchild);
}

int main()
{
    BTPTR T = NULL;
    char a[]={'a','p','c','e','s','m','q','k','d','g'};
    char b[]={'c','p','s','e','m','a','k','q','g','d'};
    T = create(a,b,9,0);

    pre(T);
    cout << endl;

    cout << cntleaf(T);

    return 0;
}
