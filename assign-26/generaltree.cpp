#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  char data;
  gtnode* child[5];
}* GTPTR;

GTPTR getnode(int k){
  GTPTR temp = new gtnode;
  temp->data = k;
  for(int i=0;i<5;i++){
    temp->child[i] = NULL;
  }
}

GTPTR create(GTPTR T,string a,int n){
  static int i = 0;
  if(i>=n) return NULL;
  if(a[i] == ')'){i++;return NULL;}
  T = getnode(a[i++]);
  for(int j=0;j<5;j++){
    T->child[j] = create(T->child[j],a,n);
    if(!T->child[j]) break;
  }
  return T;
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
  cout << "Enter the string." << endl;
  string s;cin >> s;
  GTPTR T = NULL;
  T = create(T,s,s.size());
  pre(T);

  cin.get();
  cin.get();
  return 0;
}
