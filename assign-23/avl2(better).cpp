#include <bits/stdc++.h>
using namespace std;

typedef struct bstnode{
  struct bstnode * lchild;
  int data;
  bstnode* rchild;
  int hl,hr;
}* BSTPTR;

BSTPTR get(int x){
  BSTPTR temp = new struct bstnode;
  temp->data = x;
  temp->lchild = temp->rchild = NULL;
  temp->hl = temp->hr = -1;
  return temp;
}

void add(int k,BSTPTR &T){
  if(!T){
    T = get(k);
    return;
  }

  if(T->data > k) {
    add(k,T->lchild);
    T->hl++;
  }
  else if(T->data < k) {
    add(k,T->rchild);
    T->hr++;
  }
}

void pre(BSTPTR T){
  if(!T) return;
  cout << T->data << " " << T->hr << T->hl << endl;
  pre(T->lchild);
  pre(T->rchild);
}

void ino(BSTPTR T){
  if(!T) return;
  ino(T->lchild);
  cout << T->data << " ";
  ino(T->rchild);
}

int assign(BSTPTR &T){
  if(!T) return -2;
  T->hl = assign(T->lchild) + 1;
  T->hr = assign(T->rchild) + 1;
  return max(T->hl,T->hr);
}

void rotright(BSTPTR &k1,BSTPTR &k2){
  k1->lchild = k2->rchild;
  k2->rchild = k1;
}

void printlevelorder(queue<BSTPTR> &q){
    if(q.size() == 1){return ;}
    BSTPTR temp = new struct bstnode;
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

void rotleft(BSTPTR &k1,BSTPTR &k2){
  k1->rchild = k2->lchild;
  k2->lchild = k1;
}

void avl(BSTPTR &T,int x){
  if(!T) return;
  if(T->data < x) avl(T->rchild,x);
  else if(T->data  > x) avl(T->lchild,x);

  if(T->hl-T->hr > 1){
    if(T->lchild->lchild){
      BSTPTR k1,k2,k3;
      k1 = T;k2 = T->lchild;k3 = T->lchild->lchild;
      rotright(k1,k2);
      T = k2;
    }
    if(T->lchild->rchild){
      BSTPTR k1,k2,k3;
      k1 = T;k2 = T->lchild;k3 = T->lchild->rchild;
      rotleft(k2,k3);
      T->lchild = k3;
      BSTPTR k4 = T->lchild;
      rotright(k1,k4);
      T = k4;
    }
  }

  if(T->hr-T->hl > 1){
    if(T->rchild->rchild){
      BSTPTR k1,k2,k3;
      k1 = T;k2 = T->rchild;k3 = T->rchild->rchild;
      rotleft(k1,k2);
      T = k2;
    }
    if(T->rchild->lchild){
      BSTPTR k1,k2,k3;
      k1 = T;k2 = T->rchild;k3 = T->rchild->lchild;
      rotright(k2,k3);
      T->rchild = k3;
      BSTPTR k4 = T->rchild;
      rotleft(k1,k4);
      T = k4;
    }
  }
}

int main(){
  BSTPTR T = NULL;
  cout << "Give the entries." << endl;
  while(1){
    int x;cin >> x;
    if(x == -1) break;
    add(x,T);
    avl(T,x);
    int j = assign(T);
  }

  queue<BSTPTR> q;
  q.push(T);q.push(NULL);
  printlevelorder(q);

  cin.get();cin.get();
  return 0;
}

/*

9
5
6
16
13
1
7
*/
