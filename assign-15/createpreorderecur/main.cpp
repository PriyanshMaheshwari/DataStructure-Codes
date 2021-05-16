#include <iostream>
using namespace std;

struct btnode;

typedef struct btnode* BSTPTR;

struct btnode{
    BSTPTR lchild;
    int data;
    BSTPTR rchild;
};

void create(int a[],int i,int n,BSTPTR &T){
    if(i>=n){return;}
    BSTPTR temp = new struct btnode;
    temp->data = a[i];
    temp->lchild = NULL;
    temp->rchild = NULL;
    T = temp;
    int x = i;
    while(a[x] <= a[i]){x++;}
    create(a,i+1,x,T->lchild);
    create(a,x,n,T->rchild);
}

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

int main()
{
    cout << "Enter the number of entries." << endl;
    int n;cin >>n;
    int a[n];
    cout << "Enter the values of array." << endl;
    for(int i=0;i<n;i++){cin >> a[i];}
    BSTPTR T = NULL;
    create (a,0,n,T);

    inorderprint(T);

    return 0;
}
