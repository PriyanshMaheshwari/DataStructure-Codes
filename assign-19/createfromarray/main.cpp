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

void create(BTPTR &T,int a[],int n){
    int i = 0;
    queue<BTPTR> q;
    T = createnode(a[i++]);
    q.push(T);
    while(i<n){
        BTPTR temp = q.front();
        q.pop();
        temp->lchild = createnode(a[i++]);
        q.push(temp->lchild);
        if(i==n) break;
        temp->rchild = createnode(a[i++]);
        q.push(temp->rchild);
    }
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
    create(T,a,n);
    pre(T);

    return 0;
}
