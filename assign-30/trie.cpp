#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  char data;
  int fre;
  gtnode* fc;
  gtnode* ns;
}* GTPTR;

GTPTR getnode(char k){
  GTPTR temp = new gtnode;
  temp->data = k;
  temp->fre = -1;
  temp->fc = temp->ns = NULL;
}

GTPTR getnode2(int k){
  GTPTR temp = new gtnode;
  temp->fre = k;
  temp->data = '#';
  temp->fc = temp->ns = NULL;
}

GTPTR create(GTPTR T,string s,int &i,int n){
  if(i>s.size()) return NULL;
  if(i==s.size() && T==NULL){
    T = getnode2(n);
    return T;
  }

  if(T==NULL){
    T = getnode(s[i]);
    T->fc = create(T->fc,s,++i,n);
  }

  else if(T->data == s[i])
  T->fc = create(T->fc,s,++i,n);

  else
  T->ns = create(T->ns,s,i,n);

  return T;
}

void pre(GTPTR T){
  if(!T) return;
  if(T->data!='#')cout << T->data << " ";
  else cout << T->fre << " ";
  pre(T->fc);
  cout << endl;
  pre(T->ns);
}

void printpa(GTPTR T,vector<char> &v){
  if(!T) return;
  if(T->data == '#'){
    for(int i=0;i<v.size();i++) cout << v[i] ;
    cout << " " << T->fre;
    cout << endl;
    return;
  }

  v.push_back(T->data);
  printpa(T->fc,v);
    v.pop_back();
  printpa(T->ns,v);
}

int main(){
  GTPTR t = NULL;

  while(1){
    string s;cin >> s;
    int n;cin >> n;
    if(s=="#") break;
    int i=0;
    t = create(t,s,i,n);
  }

  std::vector<char> v;
  printpa(t,v);

  cin.get();
  cin.get();
  return 0;
}
