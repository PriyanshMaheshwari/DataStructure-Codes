#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode{
  char data;
  gtnode* child[10];
  int ff;
}* GTPTR;

GTPTR getnode(int k){
  GTPTR temp = new gtnode;
  temp->data = k;
  for(int i=0;i<10;i++){
    temp->child[i] = NULL;
  }
  temp->ff = -1;
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

void assignff(GTPTR &T){
  if(!T) return;
  for(int i=0;i<10;i++) assignff(T->child[i]);
  if(isleaf(T)){
    T->ff = 0;
    return;
  }
  std::vector<int> v;
  for(int i=0;i<10;i++){
    if(T->child[i]) v.push_back(T->child[i]->ff);
    else break;
  }

  sort(v.begin(),v.end(),greater<int>());
  int ma = 0;
  for(int i=0;i<v.size();i++){
    int x = v[i]+i+1;
    ma = max(x,ma);
  }

  T->ff = ma;
  return;
}

void iter(GTPTR T){
  
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

void printff(GTPTR T){
  if(!T) return;
  cout << T->data << " : " << T->ff << endl;
  for(int i=0;i<10;i++) printff(T->child[i]);
}

int main(){
  cout << "Enter the string." << endl;
  string s;cin >> s;
  GTPTR T = NULL;
  T = create(T,s,s.size());
  pre(T);
  cout << endl;
  assignff(T);
  printff(T);

  int max = 0;
  cout << endl << "TOTAL : " << max << endl;

  cin.get();
  cin.get();
  return 0;
}
/*AB)CEFGHIJ)))))))DK)L)M))*/
/*ABHN)O))I)J))C)D)EKP))LQ)))F)GM)))*/
/*ABE)F)G))CHIJKLZ)))))))DM)NV)O)P)Q)R)S)T)U)*/
