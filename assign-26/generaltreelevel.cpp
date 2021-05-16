#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  char data;
  gtnode* child[5];
}* GTPTR;

GTPTR getnode(char k){
  GTPTR temp = new gtnode;
  temp->data = k;
  for(int i=0;i<5;i++){
    temp->child[i] = NULL;
  }
}

void create(queue<GTPTR> &q){
  if(q.empty()) return;
  GTPTR T = q.front();q.pop();
  cout << "Enter the number of " << T->data << " children." << endl;
  int y;cin >> y;
  for(int i=0;i<y;i++){
    cout << "Enter the children entry." << endl;
    char x;cin >> x;
    T->child[i] = getnode(x);
    q.push(T->child[i]);
  }
  create(q);
}

void pre(GTPTR T){
  if(!T) return;
  cout << T->data;
  int i =0 ;
  while(i<5){
    pre(T->child[i]);
    if(!T->child[i]) break;
    else i++;
  }
}

int main(){
  GTPTR T = NULL;
  cout << "Enter the root entry." << endl;
  char x;cin >> x;
  T = getnode(x);
  queue<GTPTR> q;
  q.push(T);
  create(q);

  pre(T);

  cin.get();
  cin.get();
  return 0;
}
