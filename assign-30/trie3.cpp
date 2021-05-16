#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  string data;
  gtnode* fc;
  gtnode* ns;
}* GTPTR;

GTPTR getnode(string k){
  GTPTR temp = new gtnode;
  temp->data = k;
  temp->fc = temp->ns = NULL;
}

GTPTR create(GTPTR T,string s){
  if(s.size()==0) return NULL;

  if(T==NULL){
    T = getnode(s);
    return T;
  }

  else if(T->data[0] == s[0]){
    int j = 0;
    while(j<s.size() && j<T->data.size() && T->data[j] == s[j]) j++;
    string temp = T->data;
    GTPTR t = T->fc;
    T->data = T->data.substr(0,j);
    T->fc = NULL;

    if(j == temp.size())T->fc= create(T->fc,"#");
    else if(j<temp.size())T->fc = create(T->fc,temp.substr(j,temp.size()-j));

    T->fc->fc = t;

    if(j==s.size())T->fc = create(T->fc,"#");
    else if(j<s.size()) T->fc = create(T->fc,s.substr(j,s.size()-j));
  }

  else
  T->ns = create(T->ns,s);

  return T;
}

void printpa(GTPTR T,vector<string> &v){
  if(!T) return;
  if(!T->fc){
    for(int i=0;i<v.size();i++) if(v[i]!="#") cout << v[i] ;
    if(T->data != "#") cout << T->data;
    cout << endl;
    if(T->ns) printpa(T->ns,v);
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
    if(s=="#") break;
    t = create(t,s);
  }

  std::vector<string> v;
  printpa(t,v);

  cin.get();
  cin.get();
  return 0;
}
