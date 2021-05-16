#include <bits/stdc++.h>
using namespace std;
#define rchild right
#define lchild left

struct node{
  int data;
  int hl,hr;
  node* left;
  node* right;

  node(int x) : data(x),hl(0),hr(0),left(NULL),right(NULL) {};
};

typedef node* PTR;

void leftrot(PTR &T){
  PTR k1 = T;PTR k2 = T->left;
  T = k2;
  k1->left = k2->right;
  k2->right = k1;
}

void rightrot(PTR &T){
  PTR k1 = T;PTR k2 = T->right;
  T = k2;
  k1->right = k2->left;
  k2->left = k1;
}

int assign(PTR &T){
  if(!T) return 0;
  T->hl = assign(T->lchild);
  T->hr = assign(T->right);

  return max(T->hl,T->hr)+1;
}

int assign(PTR &T,int x){
  if(!T) return 0;
  if(T->data > x) T->hl = assign(T->lchild,x);
  else T->hr = assign(T->right,x);

  return max(T->hl,T->hr)+1;
}

int add(PTR &T,int x){
  if(!T){T = new node(x);return 1;}
  if(T->data > x) T->hl = add(T->left,x);
  else T->hr = add(T->right,x);

  return max(T->hl,T->hr)+1;
}

void avl(PTR &T,int x,bool &f){
  if(!T) return;
  if(T->data > x) avl(T->left,x,f);
  else avl(T->right,x,f);
  if(f) assign(T,x);

  if(T->hl - T->hr > 1){
    if(T->left->left) leftrot(T);
    else{
      rightrot(T->left);
      leftrot(T);
    }
    f = true;
    assign(T);
  }
  else if(T->hr - T->hl > 1){
    if(T->right->right) rightrot(T);
    else{
      leftrot(T->right);
      rightrot(T);
    }
    assign(T);
    f = true;
  }
}

void level(PTR T){
  queue<PTR> q;
  q.push(T);q.push(NULL);
  while(q.size()>1){
    PTR temp = q.front();q.pop();
    if(!temp){q.push(NULL);cout << endl;continue;}
    cout << temp->data << " ";
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  cout << endl;
}

void del(PTR &T){
  if(!T->lchild) T= T->lchild;
  else T=T->rchild;
}

void del(PTR &T,int x){
  if(!T) return;
  if(T->data < x) del(T->right,x);
  else if(T->data > x) del(T->left,x);
  else{
    if(!T->lchild) {T = T->rchild;return;}
    if(!T->rchild) {T = T->lchild;return;}
    else{
      PTR temp = T->left;
      while(temp->right) temp = temp->right;
      swap(T->data,temp->data);
      del(T->left,x);
    }
  //  f = true;
  }
}

int main(){
  PTR T = NULL;
  int x;cin >> x;
  while(x!=-1){
    add(T,x);
    bool f = false;
    avl(T,x,f);
    level(T);

    cin >> x;
  }

  //cin >> x;
  //while(x!=-1){
  //  bool f = false;
    del(T,5);
    assign(T);
    bool f = false;
    avl(T,x,f);
    level(T);

    //cin >> x;
  //}
}
