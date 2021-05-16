#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  gtnode* ptr[26];
  int num;
  bool leaf;
}* GTPTR;

GTPTR getnode(char k,int x){
  GTPTR temp = new gtnode;
  for(int i=0;i<26;i++) temp->ptr[i] = NULL;

  if(x==1) temp->leaf = true;
  else temp->leaf = false;

  return temp;
}

GTPTR create(GTPTR T,string s,int n,int &i){
  if(i>s.size()) return NULL;

  if(T==NULL){

    if(i==s.size()){
      T = getnode(s[i],1);
      T->num = n;
      return T;
    }
    else T = getnode(s[i],0);

  }

  int x = int(s[i])-int('a');

  T->ptr[x] = create(T->ptr[x],s,n,++i);

  return T;
}

void printpa(GTPTR T,vector<char> &v){
  if(!T) return;
  if(T->leaf){
    for(int i=0;i<v.size();i++) cout << v[i];
    cout << " " << T->num;
    cout << endl;
  }

  for(int i=0;i<26;i++) {
    char c = char(i + int('a'));
    v.push_back(c);
    printpa(T->ptr[i],v);
    v.pop_back();
  }
}

int main(){
  GTPTR t = NULL;

  while(1){
    string s;cin >> s;
    int n;cin >> n;
    if(s=="#") break;
    int i=0;
    t = create(t,s,n,i);
  }

  std::vector<char> v;
  printpa(t,v);

  cin.get();
  cin.get();
  return 0;
}
