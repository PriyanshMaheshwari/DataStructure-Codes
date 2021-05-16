#include <iostream>
using namespace std;

typedef struct btnode{
    btnode* lchild;
    int data;
    btnode* rchild;
} *BTPTR;

BTPTR get(int x){
    BTPTR temp = new btnode;
    temp->data = x;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

BTPTR create(int a[],int b[],int i,int l,int n){
    static int k = 0;
    if(k>=n) return NULL;
    if(i>l) return NULL;
    BTPTR T = get(a[k]);
    int h = 0;
    while(1){
        if(a[k] == b[h]) break;
        h++;
    }
    k++;
    T->lchild = create(a,b,i,h-1,n);
    T->rchild = create(a,b,h+1,l,n);

    return T;
}

void pre(BTPTR T){
    if(!T) return;
    cout << T->data;
    pre(T->lchild) ;
    pre(T->rchild) ;
}

int main()
{
    int n;cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    BTPTR T = NULL;
    T = create(a,b,0,n-1,n);

    pre(T);

    return 0;
}
