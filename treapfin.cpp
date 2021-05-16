#include <bits/stdc++.h>
using namespace std;
#define right rchild
#define left lchild

struct node{
  int data;
  int prio;
  node* lchild;
  node* rchild;

  node(int x,int y) : data(x),prio(y),lchild(NULL),rchild(NULL) {}
};
typedef node* TPTR;

void leftrot(TPTR &x){
  TPTR k1 = x;TPTR k2 = x->rchild;
  x = k2;
  k1->rchild = k2->lchild;
  k2->lchild = k1;
}

void rightrot(TPTR &x){
  TPTR k1 = x;TPTR k2 = x->lchild;
  x = k2;
  k1->lchild = k2->rchild;
  k2->rchild = k1;
}

TPTR add(TPTR T,int x,int y){
  if(!T){
    TPTR temp = new node(x,y);
    return temp;
  }
  else if(T->data < x)
    T->right = add(T->right,x,y);
  else
    T->left = add(T->left,x,y);

  return T;
}

void heap(TPTR &T,int x){
  if(!T) return;

  if(T->data < x) heap(T->right,x);
  else heap(T->left,x);

  int m = T->prio;
  if(T->left) m = max(m,T->left->prio);
  if(T->right) m = max(m,T->right->prio);

  if(m!=T->prio){
    if(T->left && m==T->left->prio) rightrot(T);
    else leftrot(T);
  }

}

TPTR sea(TPTR T,int x){
  if(!T) return NULL;
  if(T->data == x) return T;
  if(T->data < x)
    return sea(T->right,x);
  else
    return sea(T->left,x);
}

void level(TPTR T){
  queue<TPTR> q;
  q.push(T);q.push(NULL);
  while(q.size()>1){
    TPTR temp = q.front();q.pop();
    if(!temp){q.push(NULL);cout << endl;continue;}
    cout << temp->data << " ";
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  cout << endl;
}

void del(TPTR &T,int x){
  if(!T) return;
  if(T->data == x){
    if(!T->lchild) {T = T->rchild;return;}
    if(!T->rchild) {T = T->lchild;return;}
    int x = max(T->left->prio,T->right->prio);
    if(x == T->left->prio){
      leftrot(T);
      del(T->right,x);
    }
    else{
      rightrot(T);
      del(T->right,x);
    }
  }

  if(T->data < x) del(T->right,x);
  else del(T->left,x);
}

int main(){
  TPTR T = NULL;
  int x,y;cin >> x >> y;
  while(x!=-1){
    T = add(T,x,y);
    heap(T,x);
    //level(T);
    cin >> x >> y;
  }
  level(T);
  cin >> x;
  while(T && x!=-1){
    del(T,x);
    cout << endl;
    level(T);
    cout << endl;
    cin >> x;
  }
  if(T) level(T);
  return 0;
}
