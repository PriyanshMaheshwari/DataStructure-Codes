
#include <bits/stdc++.h>

using namespace std;

struct btnode{
    int data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR newnode(int k){
	BTPTR temp = new struct btnode;
	temp->data = k;
	temp->lchild = temp->rchild = NULL;
	return temp;
}

BTPTR create(BTPTR &T,int k){
	T = newnode(k);
  int x = 2;
  for(x;x<k;x++){
    if(k%x == 0) break;
  }

  if(k == x) return T;
  else{
    T->lchild = create(T->lchild,x);
    T->rchild = create(T->rchild,k/x);
  }

	return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data  << " ";
    pre(T->lchild);
    pre(T->rchild);
}

int main(){
  cout << "Enter the number whose factor tree you want." << endl;
  int k;cin >> k;
  BTPTR T = NULL;
  T = create(T,k);

  pre(T);
  cin.get();
  cin.get();
}
