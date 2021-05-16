#include <iostream>
#include <queue>
using namespace std;

struct btnode{
    struct btnode* lchild;
    int data;
    struct btnode* rchild;
};
typedef struct btnode* BSTPTR;
struct X{
    int b;
    BSTPTR t;
    int c;
};

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

void createnode(BSTPTR &T1,int x){
    BSTPTR temp = new struct btnode;
    temp->data = x;
    temp->lchild = NULL;
    temp->rchild = NULL;
    T1 = temp;
}

int main()
{
    cout << "Enter the number of elements." << endl;
    int n;cin >> n;int a[n];
    cout << "Enter the elements." << endl;
    for(int i=0;i<n;i++){cin >> a[i];}
    int i=0;

    BSTPTR T = NULL;
    createnode(T,a[i++]);
    queue<X> q;
    struct X lol;
    lol.b=0;
    lol.c=1000;
    lol.t=T;
    q.push(lol);

    while(i<n){
        struct X x = q.front();
        q.pop();

        if(x.t->data > a[i] && x.b <=
            a[i]){
            struct X node;
            createnode(x.t->lchild,a[i]);
            node.t = x.t->lchild;
            node.c = x.t->data-1;
            node.b = x.b;
            q.push(node);
            i++;
        }
        if(i == n){break;}
        if(x.t->data < a[i] && x.c >= a[i]){
            struct X node;
            createnode(x.t->rchild,a[i]);
            node.t = x.t->rchild;
            node.b = x.t->data+1;
            node.c = x.c;
            q.push(node);
            i++;
        }
    }

    inorderprint(T);

    return 0;
}
