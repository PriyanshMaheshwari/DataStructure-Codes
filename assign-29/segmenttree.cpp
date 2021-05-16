#include <iostream>
#include <queue>
using namespace std;

typedef struct btnode{
  btnode* lchild;
  int data;
  btnode* rchild;
}* BTPTR;

BTPTR getnode(int x,BTPTR a,BTPTR b){
  BTPTR T = new btnode;
  T->data = x;
  T->lchild = a;
  T->rchild = b;
  return T;
}

void pre(BTPTR T){
    if(!T) return;
    cout << T->data << " ";
    pre(T->lchild);
    pre(T->rchild);
}

int main(){
  queue<BTPTR> q;

  cout << "Enter the number of values." << endl;
  int n;cin >> n;
  cout << "Enter the values." << endl;
  for(int i=0;i<n;i++){
    int x;cin >> x;
    BTPTR temp = getnode(x,NULL,NULL);
    q.push(temp);
  }

  while(q.size()>1){
    BTPTR t1 = q.front();q.pop();
    BTPTR t2 = q.front();q.pop();
    BTPTR temp = getnode(t1->data+t2->data,t2,t1);
    q.push(temp);
  }

  BTPTR T = q.front();q.pop();

  pre(T);

  cin.get();
  cin.get();
  return 0;
}
