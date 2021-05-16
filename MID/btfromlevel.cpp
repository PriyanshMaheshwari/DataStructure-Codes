#include <iostream>
using namespace std;

struct lnode{
    int data;
    struct lnode *next;
};

typedef struct btnode{
  btnode *lchild;
  int data;
  btnode *rchild;
} *BTPTR;

typedef struct lnode *LPTR;

void addbegin(int x,LPTR &L){
    LPTR T;
    T = new struct lnode;
    T->data = x;
    T->next = L;
    L = T;
}

void add(int x,LPTR &L){
    if(L == NULL){addbegin(x,L);return;}
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    while(T1->next != NULL){T1 = T1->next;}
    T->data = x;
    T1->next = T;
    T->next = NULL;
}

void printl(LPTR &L){
    LPTR T;
    T = new struct lnode;
    T = L;
    while(T!=NULL){
        cout << T->data << " ";
        T = T->next;
    }
}

void deletebegin(LPTR &L){
    L = L->next;
}

void del(int y,LPTR &L){
    LPTR T;
    T = new struct lnode;
    LPTR T1;
    T1 = new struct lnode;
    T1 = L;
    if(T1->data == y){deletebegin(L);return;}
    while(T1->next->data != y){T1 = T1->next ;}
    T = T1->next;
    T1->next = T->next;
    delete(T);
}

BTPTR getnode(int x){
  BTPTR temp = new struct btnode;
  temp->data = x;
  temp->lchild = temp->rchild = NULL;
  return temp;
}

BTPTR create(BTPTR T,LPTR L,int n){
  LPTR t=L;
  for(int i=0;i<n;i++){
    if(!t) break;
    t = t->next;
  }
  if(!t) return NULL;
  else T=getnode(t->data);

  T->lchild = create(T->lchild,L,(2*n+1));
  T->rchild = create(T->rchild,L,(2*n+2));

  return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

int main(){
  LPTR L = NULL;
  cout << "Enter the values of level order of bt";
  while(1){
    int x;cin >> x;
    if(x == -1) break;
    add(x,L);
  }
  BTPTR T = NULL;
  T = create(T,L,0);
  pre(T);
  cin.get();
  cin.get();
  return 0;
}
