#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  char data;
  gtnode* fc;
  gtnode* ns;
}* GTPTR;

GTPTR getnode(char k){
  GTPTR temp = new gtnode;
  temp->data = k;
  temp->fc = temp->ns = NULL;
}

GTPTR create(GTPTR T){
  cout << "Enter the character." << endl;
  char x;cin >> x;
  if(x == '$') {return NULL;}
  T = getnode(x);
  cout << "Enter the fc of " << T->data << endl;
  T->fc = create(T->fc);
  cout << "Enter the ns of " << T->data << endl;
  T->ns = create(T->ns);
}

void pre(GTPTR T){
  if(!T) return;
  cout << T->data;
  pre(T->fc);
  pre(T->ns);
}

void printsib(GTPTR t,char x,GTPTR temp){
  if(t==NULL) return;
  if(t->data == x){
    while(temp){
      cout << temp->data;
      temp = temp->ns;
    }
    return;
  }

  printsib(t->fc,x,t->fc);
  printsib(t->ns,x,temp);
}

int main(){
  GTPTR t = NULL;
  t = create(t);
  pre(t);

  cout << endl << "Enter the char whose siblings you want." << endl;
  char x;cin >> x;
  printsib(t,x,t);

  cin.get();
  cin.get();
  return 0;
}
