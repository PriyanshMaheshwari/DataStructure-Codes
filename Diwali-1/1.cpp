#include <bits/stdc++.h>
using namespace std;

struct enode;
typedef struct vnode{
  int data;
  struct vnode* dl;
  enode* next;
}* vptr;
typedef struct enode{
  vnode* link;
  enode* next;
}* eptr;

vptr getv(int x){
  vptr temp = new vnode;
  temp->data = x;
  temp->dl = NULL;
  temp->next = NULL;
  return temp;
}

eptr gete(vptr &temp){
  eptr temp2 = new enode;
  temp2->link = temp;
  temp2->next = NULL;
  return temp2;
}

void addv(vptr &G,int x){
  if(G == NULL){G=getv(x);return;}
  vptr temp = G;
  while(temp->dl) temp=temp->dl;
  temp->dl = getv(x);
  return;
}

void adde(eptr &T,vptr &G,int x){
  vptr temp = G;
  while(temp->data != x)temp=temp->dl;

  if(!T) {T=gete(temp);return;}
  eptr t = T;
  while(t->next) t=t->next;
  t->next = gete(temp);
  return;
}

void print(vptr G){
  while(G){
    if(G->next) {cout << G->data << " : ";}
    else {G=G->dl;continue;}+
    eptr temp = G->next;
    while(temp){
      cout << temp->link->data << " ";
      temp = temp->next;
    }
    cout << endl;
    G = G->dl;
  }
}

bool check(int t,vector<int> a){
  for(int i=0;i<a.size();i++) if(a[i] == t) return true;
  return false;
}

void dfs(vptr G,vector<int> &v){
  v.push_back(G->data);
  eptr temp = G->next;
  while(temp){
    if(!check(temp->link->data,v)) dfs(temp->link,v);
    temp = temp->next;
  }
}

int main(){
  vptr G = NULL;

  cout << "Enter the number of vertices." << endl;
  int n;cin >> n;
  cout << "Enter the vertices." << endl;
  for(int i=0;i<n;i++){
    int x;cin >> x;
    addv(G,x);
  }

  vptr temp = G;
  while(temp){
    cout << "Enter neighbour of " << temp->data << " : ";
    while(1){
      int x;cin >> x;
      if(x==-1) break;
      adde(temp->next,G,x);
    }
    temp = temp->dl;
  }

  print(G);
  cout << endl;

  vector<int> v;
  cout << "Enter the number whose dfs you want." << endl;
  int k;cin >> k;
  vptr t = G;
  while(t->data != k) t=t->dl;
  dfs(t,v);
  for(int i=0;i<v.size();i++) cout << v[i] << " ";
  cout << endl;

  cin.get();cin.get();
  return 0;
}
