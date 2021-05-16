#include <bits/stdc++.h>
using namespace std;

struct node{
  int data,prio;
  node* left;
  node* right;
  node(int x,int y){
    data = x;prio = y;
    left = right = NULL;
  }
  node(int x,int y,node* k1,node* k2){
    data = x;prio = y;
    left = k1;right = k2;
  }
};
typedef node* PTR;

void split(PTR T,PTR &l,PTR &r,int k){
  if(!T) {l = r = NULL;return;}
  if(T->data > k) {split(T->left,l,T->left,k);r = T;}
  else {split(T->right,T->right,r,k);l=T;}
}

void merge(PTR &T,PTR l,PTR r){
  if(!l && !r) T = NULL;
  if(!l && r) T = r;
  if(l && !r) T = l;
  if(l->prio > r->prio){
    merge(l->right,l->right,r);
    T = l;
  }
  else{
    merge(r->left,l,r->left);
    T = r;
  }
}

void insert(PTR &T,PTR n){
  if(!T) {T = n;return;}
  if(T->prio < n->prio){
    split(T,n->left,n->right,n->data);
  }
  else{
    if(T->data > n->data) insert(T->left,n);
    else insert(T->right,n);
  }
}

void erase(PTR &T,int k){
  if(!T) return;
  if(T->data == k){merge(T,T->left,T->right);}
  else{
    if(T->data > k) erase(T->left,k);
    else erase(T->right,k);
  }
}

int main(){
  PTR T = NULL;
  while(1){
    int x,y;
    cin >> x >> y;
  }
  return 0;
}
