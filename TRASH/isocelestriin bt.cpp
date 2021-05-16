#include <bits/stdc++.h>

using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR nod(char a){
    if(a != '+'){
        BTPTR temp = new btnode;
        temp->data = a;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else return NULL;
}

BTPTR create(BTPTR &T,char a[],int n){
    static int i = 0;
    if(i == n) return T;
    T = nod(a[i]);
    if(T == NULL) return NULL;
    i++;
    T->lchild = create(T->lchild,a,n);
    i++;
    T->rchild = create(T->rchild,a,n);
    return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data;
    pre(T->lchild);
    pre(T->rchild);
}

int left(BTPTR T){
  int i=0;
  while(T){
    i++;
    T = T->lchild;
  }
  return i;
}

int right(BTPTR T){
  int i=0;
  while(T){
    i++;
    T = T->rchild;
  }
  return i;
}

void check(BTPTR T,BTPTR root,int &cnt){
  if(!T) return;
  cnt += min(left(T),right(T));
  int j = par(T,root);
  if(i<0) cnt += min(right(T),-i);
  else if(i>0) cnt += min(left(T),i);
  check(T->lchild,root,cnt);
  check(T->rchild,root,cnt);
}

int main()
{
    int n;cin >> n;
    char a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    BTPTR T = NULL;
    T = create(T,a,n);
    pre(T);

    int cnt = 0;


    return 0;
}
