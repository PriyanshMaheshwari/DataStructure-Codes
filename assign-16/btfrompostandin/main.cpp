#include <iostream>

using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

int pass(int i,char c,char b[],int n){
    int j = i;
    while(j<=n ){
        if(b[j] == c) return j;j++;
    }
}

BTPTR create(char a[],char b[],int n,int i){
    static int k = n;
    if(i>n) return NULL;
    BTPTR temp = new btnode;
    temp->data = a[k--];
    temp->lchild = temp->rchild = NULL;
    if(i==n) return temp;
    int x = pass(i,temp->data,b,n);
    temp->rchild = create(a,b,n,x+1);
    temp->lchild = create(a,b,x-1,i);
    return temp;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}


int main()
{
    cout << "Enter the number of elements." << endl;
    int n;cin >> n;
    char a[n],b[n];
    cout << "Enter the postorder." << endl;
    for(int i=0;i<n;i++) cin >>a[i];
    cout << "Enter the inorder." << endl;
    for(int i=0;i<n;i++) cin >>b[i];

    BTPTR T = NULL;
    T = create(a,b,n-1,0);
    pre(T);

    return 0;
}
