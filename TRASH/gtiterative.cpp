#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  int data;
  gtnode* ptr[5];
}* GTPTR;

GTPTR getnode(int x){
  GTPTR temp = new gtnode;
  temp->data = x;
  for(int i=0;i<5;i++) temp->ptr[i] = NULL;
  return temp;
}

void pre(GTPTR T){
  if(!T) return;
  cout << T->data << " ";
  for(int i=0;i<5;i++) pre(T->ptr[i]);
}

int main(){
  GTPTR T = NULL;
  stack<GTPTR> S;
  cout << "Enter the root value." << endl;
  int a;cin >> a;
  T = getnode(a);
  S.push(T);

  while(!S.empty()){
    GTPTR temp = S.top();
    cout << "Enter " << temp->data << " child.";
    int x;cin >> x;
    if(x == -1){
      if(S.size()!=1) S.pop();
      else break;
    }
    else{
      GTPTR temp2 = getnode(x);
      int i=0;
      while(temp->ptr[i]) i++;
      temp->ptr[i] = temp2;
      S.push(temp2);
    }


  T = S.top();

  pre(T);
  cin.get();cin.get();
  return 0;
}
