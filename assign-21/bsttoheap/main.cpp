#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct btnode{
    struct btnode* lchild;
    int data;
    struct btnode* rchild;
};

struct bnode{
    struct bnode* lchild;
    int data;
    struct bnode* rchild;
};

typedef struct bnode* BTPTR;
typedef struct btnode* BSTPTR;

void add(BSTPTR &T,int k){
    if(T == NULL){
        BSTPTR temp = new struct btnode;
        temp->data = k;
        temp->lchild = NULL;
        temp->rchild = NULL;
        T = temp;
    }
    else if(T->data > k){add(T->lchild,k);}
    else add(T->rchild,k);
}

void inoarr(BSTPTR T,vector<int> &a){
    if(T == NULL) return;
    inoarr(T->lchild,a);
    a.push_back(T->data);
    inoarr(T->rchild,a);
}

BTPTR create(BTPTR t,vector<int> &v,int i){
    if(i>=v.size()) return NULL;
    BTPTR temp = new struct bnode;
    temp->data = v[i];
    temp->lchild = temp->rchild = NULL;
    t = temp;
    temp->lchild = create(t->lchild,v,2*i+1);
    temp->rchild = create(t->rchild,v,2*i+2);
    return t;
}

void inorderprint(BTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

int main()
{
    BSTPTR T = NULL;
    cout << "Enter the values and press -1 to end." << endl;
    while(1){
        int x;cin >> x;
        if(x == -1){break;}
        add(T,x);
    }

    vector<int> v;
    inoarr(T,v);
//    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    BTPTR t = NULL;
    t = create(t,v,0);
    inorderprint(t);

    return 0;
}
