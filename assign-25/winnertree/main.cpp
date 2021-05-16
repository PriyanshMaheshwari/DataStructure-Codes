#include <bits/stdc++.h>
using namespace std;

struct btnode{
    struct btnode *lchild;
    int data;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR getnode(int k){
    BTPTR temp = new btnode;
    temp->data = k;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

BTPTR create(BTPTR &T,int a[],int n,int l,int &i){
    if(i>=n) return NULL;
    if(pow(2,l) == n){
        T = getnode(a[i++]);
    }
    else{
        T = getnode(-1);
        T->lchild = create(T->lchild,a,n,l+1,i);
        T->rchild = create(T->rchild,a,n,l+1,i);
    }
    return T;
}

void pre(BTPTR T){
    if(T == NULL) return;
    cout << T->data << " ";
    pre(T->lchild);
    pre(T->rchild);
}

int win(BTPTR T){
    if(T == NULL) return -1;
    if(!T->lchild && !T->rchild) return T->data;
    return max(win(T->lchild),win(T->rchild));
}

int main(){
    cout << "Enter the number of elements." << endl;
    int n;cin >> n;
    cout << "Enter the elements. " << endl;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    BTPTR T = NULL;
    int i =0;
    T = create(T,a,n,0,i);
    //pre(T);
    cout << "Winner is : " << win(T);

    return 0;
}
