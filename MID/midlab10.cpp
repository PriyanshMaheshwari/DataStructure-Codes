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

GTPTR create(GTPTR T,string a,int n,int &x){
  static int i = 0;
  if(i>=n) return NULL;
  if(a[i] == ')'){i++;return NULL;}
  T = getnode(a[i++]);x++;
  for(int j=0;j<5;j++){
    T->child[j] = create(T->child[j],a,n,x);
    if(!T->child[j]) break;
  }
  return T;
}

void pri(int n,vector<GTPTR> &p,vector<char> &a,int &cnt){
  if(a.size() == n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cnt++;
    cout << endl;
    return;
  }

  for(int i=0;i<p.size();i++){
    GTPTR t = p[i];
    p.erase(p.begin()+i);
    for(int j=0;j<5;j++) if(t->child[j]) p.push_back(t->child[j]);
    a.push_back(t->data);
    pri(n,p,a,cnt);
    a.pop_back();
    for(int j=0;j<5;j++) if(t->child[j]) p.pop_back();
    p.insert(p.begin()+i,t);
  }
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
  int n = 0;
  T = create(T,s,s.size(),n);

  cout << endl;
  vector<char> a;
  vector<GTPTR> p;
  p.push_back(T);
  int cnt = 0;
  pri(n,p,a,cnt);
  cout << endl << "Total number of ways : " << cnt << endl;

  cin.get();
  cin.get();
  return 0;
}
