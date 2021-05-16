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

BTPTR create2(int pre[],int post[],int st,int en,int n){
    static int k = 0;
    if( k>=n || st>en) return NULL;
    BTPTR T = get(pre[k++]);
    int h = st;
    if(st == en) {return T;}
    while(h<=en){
        if(pre[k] == post[h]) break;
        h++;
    }
    T->lchild = create2(pre,post,st,h,n);
    T->rchild = create2(pre,post,h+1,en,n);

    return T;
}

void pre(BTPTR T){
    if(!T) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

int main(){
    int n;cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    BTPTR T = NULL;
    T = create2(a,b,0,n-1,n);

    pre(T);

    return 0;
}
