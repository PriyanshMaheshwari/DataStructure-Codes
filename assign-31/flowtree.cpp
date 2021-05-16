#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  char data;
  gtnode* child[10];
  int dep;
}* GTPTR;

GTPTR getnode(int k){
  GTPTR temp = new gtnode;
  temp->data = k;
  for(int i=0;i<10;i++){
    temp->child[i] = NULL;
  }
  temp->dep = -1;
}

void assigndep(GTPTR T,int n){
  if(!T) return;
  T->dep = n;
  for(int i=0;i<10;i++) assigndep(T->child[i],n+1);
}

int chi(GTPTR T){
  int i=0;
  for(i;i<10;i++) if(T->child[i] == NULL) return i;
  return i;
}

bool isleaf(GTPTR T){
  if(T->child[0] == NULL) return true;
  else return false;
}

void iter(GTPTR T,int &max){
  if(!T) return;
  int x = T->dep+chi(T);
  if(x==max && isleaf(T)) max++;
  if(x>max) max=x;
  for(int i=0;i<10;i++) iter(T->child[i],max);
}

GTPTR create(GTPTR T,string a,int n){
  static int i = 0;
  if(i>=n) return NULL;
  if(a[i] == ')'){i++;return NULL;}
  T = getnode(a[i++]);
  for(int j=0;j<10;j++){
    T->child[j] = create(T->child[j],a,n);
    if(!T->child[j]) break;
  }
  return T;
}

void pre(GTPTR T){
  if(!T) return;
  cout << T->data;
  int i =0 ;
  while(i<10){
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
  assigndep(T,0);
  int max = 0;
  iter(T,max);
  cout << endl << "TOTAL : " << max << endl;

  cin.get();
  cin.get();
  return 0;
}
/*AB)CEFGHIJ)))))))DK)L)M))*/
/*ABHN)O))I)J))C)D)EKP))LQ)))F)GM)))*/
/*ABE)F)G))CHIJKLZ)))))))DM)NV)O)P)Q)R)S)T)U)*/
