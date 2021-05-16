#include <iostream>

using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;


BTPTR create(char a[],char b[],int i,int n,int n1){
    BTPTR temp = new btnode;
    static int k = 0;
    if(k>=n1) return NULL;
    if(i>n) return NULL;

    temp->data = a[k++];
    temp->lchild = temp->rchild = NULL;
    if(i==n) return temp;

    int x;
    for(x = i;x<=n;x++){
        if(b[x] == temp->data) break;
    }

    temp->lchild = create(a,b,i,x-1,n1);
    temp->rchild = create(a,b,x+1,n,n1);
    return temp;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

void ino(BTPTR T){
    if(T==NULL) return;
    ino(T->lchild);
    cout << T->data;
    ino(T->rchild);
}

int main()
{
    /*cout << "Enter the number of elements." << endl;
    int n;cin >> n;
    char a[n],b[n];
    cout << "Enter the preorder." << endl;
    for(int i=0;i<n;i++) cin >>a[i];
    cout << "Enter the inorder." << endl;
    for(int i=0;i<n;i++) cin >>b[i];*/

    BTPTR T = NULL;
    char a[]={'s','m','k','l','t','b','j','e','g','d'};
    char b[]={'k','m','t','l','b','s','j','g','d','e'};

    T = create(a,b,0,9,10);

    pre(T);
    cout << endl;
    ino(T);

    return 0;
}
