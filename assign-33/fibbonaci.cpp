#include <iostream>
#include <queue>
using namespace std;

struct btnode{
    struct btnode* lchild;
    int data;
    struct btnode* rchild;
};

typedef struct btnode* BSTPTR;


BSTPTR getnode(int k){
  BSTPTR temp = new struct btnode;
  temp->data = k;
  temp->lchild = NULL;
  temp->rchild = NULL;
  return temp;
}

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

void printlevelorder(queue<BSTPTR> &q){
    if(q.size() == 1){return ;}
    BSTPTR temp = new struct btnode;
    temp = q.front();
    q.pop();
    if(temp == NULL){cout << endl;q.push(temp);}
    else{
        cout << temp->data << " ";
        if(temp->lchild){q.push(temp->lchild);}
        if(temp->rchild){q.push(temp->rchild);}
    }
    printlevelorder(q);
}


void preorderprint(BSTPTR T){
    if(T==NULL){return ;}
    cout << T->data << " ";
    preorderprint(T->lchild);
    preorderprint(T->rchild);
}

void inorderprint(BSTPTR T){
    if(T==NULL){return;}
    inorderprint(T->lchild);
    cout << T->data << " ";
    inorderprint(T->rchild);
}

void postorderprint(BSTPTR T){
    if(T==NULL){return;}
    postorderprint(T->lchild);
    postorderprint(T->rchild);
    cout << T->data << " ";
}

int mi(BSTPTR T){
    while(T->lchild != NULL)
        T= T->lchild;
    return T->data;
}

int ma(BSTPTR T){
    while(T->rchild != NULL){
        T=T->rchild;
    return T->data;
}
}

BSTPTR create(BSTPTR &T,BSTPTR &root,int &i,int n){
  if(i==n) return T;


  BSTPTR temp;
  if(i == 0){
    temp = getnode(1);
  }
  else{
    temp = new btnode;
    if(T->lchild) temp->data = T->data+T->lchild->data;
    else temp->data = T->data+T->data;
    temp->lchild = T;
    int j = 0;
    BSTPTR temp2 = create(T,root,j,i-1);
    temp->rchild = temp2;
  }
  root = temp;
  i++;
  return create(root,root,i,n);
}

int main(){

    BSTPTR T = NULL;
    cout << "Enter the value." << endl;
    int n;cin >> n;

    int i=0;
    T = create(T,T,i,n);

    preorderprint(T);
    cout << endl;


    cin.get();
    cin.get();
    return 0;
}
