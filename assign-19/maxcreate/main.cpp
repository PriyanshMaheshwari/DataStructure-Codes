#include <iostream>
#include <queue>
using namespace std;

struct btnode;
typedef struct btnode *BTPTR;
struct btnode{
    int data;
    BTPTR lchild;
    BTPTR rchild;
};

BTPTR createnode(int x){
    BTPTR temp = new struct btnode;
    temp->data = x;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

int m(int a[],int n,int i){
    int ma = INT_MIN;
    int mai = i;
    for(int j = i;j<=n;j++){
        if(ma<a[j]){
            ma = a[j];mai = j;
        }
    }
    return mai;
}

BTPTR create(BTPTR T,int a[],int n,int i){
    if(i>n || i<0) return NULL;
    int f = 0;
    int x = m(a,n,i);
    T = createnode(a[x]);
    if(i==n) return T;
    T->lchild = create(T->lchild,a,x-1,i);
    T->rchild = create(T->rchild,a,n,x+1);
    return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data  << " ";
    pre(T->lchild);
    pre(T->rchild);
}

int main()
{
    cout << "Enter the no. of elements." << endl;
    int n;cin >> n;
    int a[n];
    cout << "Enter the elements." << endl;
    for(int i=0;i<n;i++) cin >> a[i];
    BTPTR T = NULL;
    T = create(T,a,n-1,0);
    pre(T);
}
